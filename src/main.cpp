#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <LedControl.h>

/* 
 * dataPin		pin on the Arduino where data gets shifted out
 * clockPin		pin for the clock
 * csPin		pin for selecting the device 
 * numDevices	maximum number of devices that can be controled
 */  
LedControl matrix = LedControl(12, 10, 11, 4);

void setup() {
  Serial.begin(9600);

  for (int index = 0; index < matrix.getDeviceCount(); index++) {
    matrix.shutdown(index, false);
    matrix.setIntensity(index, 1);
    matrix.clearDisplay(index);
  }
}

void loop() {
  // for (int index = 0; index < matrix.getDeviceCount(); index++) {
  //   matrix.setDigit(index, 0, 0x2, false);
  //   delay(1000);
  //   matrix.clearDisplay(index);
  // }

  matrix.setChar(0, 0, 'd', false);

  // matrix.setRow(0, 0, B11111111);
  // matrix.setRow(1, 2, B11111111);
  // matrix.setRow(2, 4, B11111111);
  // matrix.setRow(3, 6, B11111111);

  matrix.setIntensity(0, 0);
  matrix.setIntensity(1, 1);
  matrix.setIntensity(2, 8);
  matrix.setIntensity(3, 15);
  delay(5000);
  for (int index = 0; index < matrix.getDeviceCount(); index++) {
    matrix.clearDisplay(index);
  }
  delay(5000);
}