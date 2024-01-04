#ifndef NeoPixel_h
#define NeoPixel_h

#include <vector>  

#include <Arduino.h>

class NeoPixel {
public:
  NeoPixel();
  static void setupNeoPixel();
  static void setNeoPixelColour(String colour);
  static void flash(int numberOfFlashes, const std::vector<String>& colors, String finalColour);
};

#endif
