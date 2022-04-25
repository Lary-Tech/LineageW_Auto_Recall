#include <Arduino.h>
class Keyboard {
    public:
        Keyboard();
        void clickPrtScn();
        void clickF12();
        void clickF10();
        void clickF9();
        void releaseKey();
    private:
        uint8_t buf[8];
};