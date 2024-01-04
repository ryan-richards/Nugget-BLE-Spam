#include "Arduino.h"
#include "Screen.h"
#include "SH1106.h"
#include "graphics.h"

SH1106Wire display(0x3C, 35, 36);

const char* Screen::sectionText = "NUGGET BLE SPAM"; // Define and initialize sectionText

Screen::Screen() {
sectionText = "NUGGET BLE SPAM";
}

void Screen::initDisplay() {
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(DejaVu_Sans_Mono_10);
}

void Screen::displaySplash(uint8_t sec) {
  display.clear();
  display.drawString(35, 25, "BLE SPAM");
  display.drawString(52, 40, "@Catzpacho");
  display.drawString(20, 40, "v1.0");
  display.display();
  delay(sec * 1000);
}

void Screen::displayBluetoothOff() {
  display.clear();
  display.drawXbm(0, 0, 128, 64, plain_bits);
  display.drawLine(0, 53, 127, 53);
  display.drawLine(0, 54, 127, 54);
  display.drawString(0, 54, sectionText);
  display.display();
}

void Screen::displayBluetoothOn() {
  display.clear();
  display.drawXbm(0, 0, 128, 64, blue_bits);
  display.drawLine(0, 53, 127, 53);
  display.drawLine(0, 54, 127, 54);
  display.drawString(0, 54, sectionText);
  display.display();
}

void Screen::updateSectionText(const char* newText) {
  sectionText = newText;
  display.setColor(BLACK);
  display.fillRect(0, 55, 128, 9);
  display.setColor(WHITE);

  // Draw the new text in the same location
  display.drawString(0, 54, newText);
  display.display();
}
