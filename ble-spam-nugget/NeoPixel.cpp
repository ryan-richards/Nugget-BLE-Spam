#include <Adafruit_NeoPixel.h>
#include "NeoPixel.h"

Adafruit_NeoPixel strip{ 1, 10, NEO_GRB + NEO_KHZ800 };

NeoPixel::NeoPixel() {
}

void NeoPixel::setupNeoPixel() {
  strip.begin();
  strip.clear();
  strip.show();
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.show();
  strip.setBrightness(100);
}

void NeoPixel::setNeoPixelColour(String colour) {
  if (colour == "red") {
    strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.show();
  } else if (colour == "green") {
    strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.show();
  } else if (colour == "blue") {
    strip.setPixelColor(0, strip.Color(0, 0, 255));
    strip.show();
  } else if (colour == "yellow") {
    strip.setPixelColor(0, strip.Color(255, 255, 0));
    strip.show();
  } else if (colour == "purple") {
    strip.setPixelColor(0, strip.Color(255, 0, 255));
    strip.show();
  } else if (colour == "cyan") {
    strip.setPixelColor(0, strip.Color(0, 255, 255));
    strip.show();
  } else if (colour == "white") {
    strip.setPixelColor(0, strip.Color(255, 255, 255));
    strip.show();
  } else if (colour == "off") {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.show();
  } else {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.show();
  }
}

void NeoPixel::flash(int numberOfFlashes, const std::vector<String>& colors, String finalColour) {
  for (int i = 0; i < numberOfFlashes; ++i) {
    for (const auto& color : colors) {
      setNeoPixelColour(color);
      delay(500);
    }
  }
  setNeoPixelColour(finalColour);
}
