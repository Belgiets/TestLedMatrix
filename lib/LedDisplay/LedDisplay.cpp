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

void LedDisplay::displayTime(char* time) {
    String timeStr;
    timeStr += time;

    String minutes = timeStr.substring(3, 5);
    
    //show hours
    String hoursFirst = timeStr.substring(0, 1);
    displayChar(hoursFirst, 0);
    String hoursSecond = timeStr.substring(1, 2);
    displayChar(hoursSecond, 1);

    // show minutes
    String minutesFirst = timeStr.substring(3, 4);
    displayChar(minutesFirst, 2);
    String minutesSecond = timeStr.substring(4, 5);
    displayChar(minutesSecond, 3);
}

void LedDisplay::displayChar(String value, int matrix) {
    byte rows[8];
    fillRows(rows, value);
    
    for (int index = 0; index < 8; index++) {
        matrices.setRow(matrix, index, rows[index]);
    }
};

void LedDisplay::test(void) {
    byte rows[8];
    fillRows(rows, "0");
    
    for (int index = 0; index < 8; index++) {
        Serial.println(rows[index], BIN);
        matrices.setRow(0, index, rows[index]);
    }
};

void LedDisplay::fillRows(byte rows[], String value) {
    if (value == "0") {
        rows[0] = B00000000;
        rows[1] = B00011000;
        rows[2] = B00100100;
        rows[3] = B00100100;
        rows[4] = B00100100;
        rows[5] = B00100100;
        rows[6] = B00011000;
        rows[7] = B00000000;
    } else if (value == "1") {
        rows[0] = B00000000;
        rows[1] = B00001000;
        rows[2] = B00011000;
        rows[3] = B00001000;
        rows[4] = B00001000;
        rows[5] = B00001000;
        rows[6] = B00011100;
        rows[7] = B00000000;
    } else if (value == "2") {
        rows[0] = B00000000;
        rows[1] = B00111000;
        rows[2] = B00000100;
        rows[3] = B00000100;
        rows[4] = B00111000;
        rows[5] = B00100000;
        rows[6] = B00111100;
        rows[7] = B00000000;
    } else if (value == "3") {
        rows[0] = B00000000;
        rows[1] = B00111000;
        rows[2] = B00000100;
        rows[3] = B00011000;
        rows[4] = B00000100;
        rows[5] = B00000100;
        rows[6] = B00111000;
        rows[7] = B00000000;
    } else if (value == "4") {
        rows[0] = B00000000;
        rows[1] = B00001000;
        rows[2] = B00011000;
        rows[3] = B00101000;
        rows[4] = B00111100;
        rows[5] = B00001000;
        rows[6] = B00001000;
        rows[7] = B00000000;
    } else if (value == "5") {
        rows[0] = B00000000;
        rows[1] = B00111100;
        rows[2] = B00100000;
        rows[3] = B00111000;
        rows[4] = B00000100;
        rows[5] = B00000100;
        rows[6] = B00111000;
        rows[7] = B00000000;
    } else if (value == "6") {
        rows[0] = B00000000;
        rows[1] = B00011000;
        rows[2] = B00100000;
        rows[3] = B00111000;
        rows[4] = B00100100;
        rows[5] = B00100100;
        rows[6] = B00011000;
        rows[7] = B00000000;
    } else if (value == "7") {
        rows[0] = B00000000;
        rows[1] = B00111100;
        rows[2] = B00000100;
        rows[3] = B00000100;
        rows[4] = B00001000;
        rows[5] = B00010000;
        rows[6] = B00010000;
        rows[7] = B00000000;
    } else if (value == "8") {
        rows[0] = B00000000;
        rows[1] = B00011000;
        rows[2] = B00100100;
        rows[3] = B00011000;
        rows[4] = B00100100;
        rows[5] = B00100100;
        rows[6] = B00011000;
        rows[7] = B00000000;
    } else if (value == "9") {
        rows[0] = B00000000;
        rows[1] = B00011000;
        rows[2] = B00100100;
        rows[3] = B00100100;
        rows[4] = B00011100;
        rows[5] = B00000100;
        rows[6] = B00011000;
        rows[7] = B00000000;
    }
};