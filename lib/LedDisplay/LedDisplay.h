#ifndef LedDisplay_h
#define LedDisplay_h

#include <LedControl.h>

class LedDisplay {
private:
    int intensity;
    LedControl matrices;

public:
    LedDisplay(int dataPin, int clockPin, int csPin);
    void begin(void);
    void clearAll(void);
    void test(void);
};

#endif