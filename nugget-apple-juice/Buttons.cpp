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
int selectedPacket = 0;


const char* deviceNames[] = {
  "Airpods",
  "Airpods Pro",
  "Airpods Max",
  "Airpods Gen 2",
  "Airpods Gen 3",
  "Airpods Pro Gen 2",
  "Power Beats",
  "Power Beats Pro",
  "Beats Solo Pro",
  "Beats Studio Buds",
  "Beats Flex",
  "Beats X",
  "Beats Solo 3",
  "Beats Studio 3",
  "Beats Studio Pro",
  "Betas Fit Pro",
  "Beats Studio Buds Plus",
  "AppleTV Setup",
  "AppleTV Pair",
  "AppleTV New User",
  "AppleTV AppleID Setup",
  "AppleTV Wireless Audio Sync",
  "AppleTV Homekit Setup",
  "AppleTV Keyboard Setup",
  "AppleTV Connecting to Network",
  "Homepod Setup",
  "Setup New Phone",
  "Transfer Number",
  "TV Color Balance",
  "Apple Vision Pro",
  "Random Spam",
  "Extended Attack",
  "Flipper Zero"
};

int numPackets = sizeof(deviceNames) / sizeof(deviceNames[0]);

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
          selectedPacket = (selectedPacket - 1 + numPackets) % numPackets;
          updateScreenWithActiveSSID();
          break;
        case 3: // Button 3 (rt_btn) was pressed
          selectedPacket = (selectedPacket + 1) % numPackets;
          updateScreenWithActiveSSID();
          break;
      }
    }
  }
}

void Buttons::updateScreenWithActiveSSID() {
  Screen::updateSectionText(deviceNames[selectedPacket]);
}
