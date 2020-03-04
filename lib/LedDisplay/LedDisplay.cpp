#include <Arduino.h>
#include <LedDisplay.h>
#include <SPI.h>
#include <LedControl.h>

LedDisplay::LedDisplay(int dataPin, int clockPin, int csPin):matrices(dataPin, clockPin, csPin, 4) {};

void LedDisplay::begin(void) {
    for (int index = 0; index < matrices.getDeviceCount(); index++) {
        matrices.shutdown(index, false);
        matrices.setIntensity(index, 1);
        matrices.clearDisplay(index);
    }
};

void LedDisplay::clearAll(void) {
    for (int index = 0; index < matrices.getDeviceCount(); index++) {
        matrices.clearDisplay(index);
    }
}

void LedDisplay::test(void) {
    matrices.setRow(0, 0, B11111111);
    matrices.setRow(1, 0, B11111111);
    matrices.setRow(2, 0, B11111111);
    matrices.setRow(3, 0, B11111111);

    matrices.setIntensity(0, 0);
    matrices.setIntensity(1, 1);
    matrices.setIntensity(2, 8);
    matrices.setIntensity(3, 15);
};