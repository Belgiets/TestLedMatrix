#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <LedControl.h>
#include <iarduino_RTC.h>
#include <LedDisplay.h>

/* 
 * dataPin		pin on the Arduino where data gets shifted out
 * clockPin		pin for the clock
 * csPin		pin for selecting the device 
 * numDevices	maximum number of devices that can be controled
 */  
// LedControl matrix = LedControl(12, 10, 11, 4);
LedDisplay display = LedDisplay(12, 10, 11);

/**
 * name, rst , clk, data;
 */
iarduino_RTC watch = iarduino_RTC(RTC_DS1302, 2, 3, 4);

void setup() {
  Serial.begin(9600);
  watch.begin();
  //sec/min/hour/day/month/year/day of the week
  // watch.settime(-1, 27, 17, 4, 3, 2020, 4);
  // watch.blinktime(2);
    
  // for (int index = 0; index < matrix.getDeviceCount(); index++) {
  //   matrix.shutdown(index, false);
  //   matrix.setIntensity(index, 1);
  //   matrix.clearDisplay(index);
  // }
  display.begin();
}

void loop() {
  // for (int index = 0; index < matrix.getDeviceCount(); index++) {
  //   matrix.setDigit(index, 0, 0x2, false);
  //   delay(1000);
  //   matrix.clearDisplay(index);
  // }
  
  // matrix.setRow(0, 0, B11111111);
  // matrix.setRow(1, 2, B11111111);
  // matrix.setRow(2, 4, B11111111);
  // matrix.setRow(3, 6, B11111111);

  // matrix.setIntensity(0, 0);
  // matrix.setIntensity(1, 1);
  // matrix.setIntensity(2, 8);
  // matrix.setIntensity(3, 15);
  // delay(1000);
  // for (int index = 0; index < matrix.getDeviceCount(); index++) {
  //   matrix.clearDisplay(index);
  // }
  display.clearAll();  
  Serial.println(watch.gettime("H:i"));
  display.displayTime(watch.gettime("H:i"));
  delay(30000);
}