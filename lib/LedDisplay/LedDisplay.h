#ifndef LedDisplay_h
#define LedDisplay_h

#include <LedControl.h>

class LedDisplay {
private:
    int intensity;
    LedControl matrices;
    void displayChar(String value, int matrix);
    void fillRows(byte rows[], String value);

public:
    LedDisplay(int dataPin, int clockPin, int csPin);
    void begin(void);
    void clearAll(void);
    void displayTime(char* time);
    void test(void);
};

#endif