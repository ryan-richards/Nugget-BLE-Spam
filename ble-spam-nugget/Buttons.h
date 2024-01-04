#ifndef Buttons_h
#define Buttons_h

#include <Arduino.h>

extern const int buttonPins[];
extern const int numButtons;
extern int lastPressedButton;
extern int selectedPacket;

class Buttons {
public:
  Buttons();
  static void setupButtons();
  static void updateButtons();
  static void updateScreenWithActiveSSID();
};

#endif
