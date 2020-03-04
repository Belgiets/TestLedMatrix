#include <Arduino.h>
#include <SPI.h>
#include <LedControl.h>
#include <iarduino_RTC.h>
#include <LedDisplay.h>
#include <RBD_Timer.h>

/* 
 * dataPin		pin on the Arduino where data gets shifted out
 * clockPin		pin for the clock
 * csPin		pin for selecting the device
 */
LedDisplay display = LedDisplay(12, 10, 11);

/**
 * name, rst , clk, data;
 */
iarduino_RTC watch = iarduino_RTC(RTC_DS1302, 2, 3, 4);

RBD::Timer minuteTimer(60000);
RBD::Timer lightSyncTimer(1000);
int analogPin = A0;

void setup() {
  Serial.begin(9600);
  watch.begin();
  //sec/min/hour/day/month/year/day of the week
  // watch.settime(-1, 27, 17, 4, 3, 2020, 4);
  // watch.blinktime(2);
  display.begin();
}

void loop() {
  if (minuteTimer.isExpired()) {
    display.clearAll();
    display.displayTime(watch.gettime("H:i"));
    minuteTimer.restart();
  }

  if (lightSyncTimer.isExpired()) {
    int light = analogRead(analogPin);

    if (light > 900) {
      display.SetIntensity(15);
    } else if (light > 700) {
      display.SetIntensity(11);
    } else if (light > 350) {
      display.SetIntensity(7);
    } else {
      display.SetIntensity(0);
    }

    Serial.println(light);
    lightSyncTimer.restart();
  }
}