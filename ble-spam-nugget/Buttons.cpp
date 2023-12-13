// Buttons.cpp

#include "Buttons.h"
#include <Bounce2.h>
#include "Vars.h"
#include "Screen.h"
#include "NeoPixel.h"

Bounce b = Bounce();

const int buttonPins[] = {up_btn, dn_btn, lt_btn, rt_btn};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

Bounce buttons[numButtons];

int lastPressedButton = -1;

Buttons::Buttons() {
}

void Buttons::setupButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(5); // Adjust the debounce interval if needed
  }
}

void Buttons::updateButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();

    // Check if a button was pressed (fell)
    if (buttons[i].fell()) {
      lastPressedButton = i;  // Store the index of the last pressed button

      switch (i) {
        case 0: // Button 0 (up_btn) was pressed
            NeoPixel::setNeoPixelColour("blue");
            Screen::displayBluetoothOn();
          break;
        case 1: // Button 1 (dn_btn) was pressed
          // Add your logic for the "down" button here
          // Example: perform an action for the "down" button
          NeoPixel::setNeoPixelColour("off");
          Screen::displayBluetoothOff();
          break;
        case 2: // Button 2 (lt_btn) was pressed
          break;
        case 3: // Button 3 (rt_btn) was pressed
          break;
      }
    }
  }
}

/* void Buttons::updateScreenWithActiveSSID() {
  Screen::updateSectionText();
} */
