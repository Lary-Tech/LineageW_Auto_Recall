#ifndef Morse_h
#define Morse_h

#include <Arduino.h>
class Keyboard {
    public:
        Keyboard();
        void clickPrtScn();
        void clickF12();
        void releaseKey();
    private:
        uint8_t buf[8];
};

#endif