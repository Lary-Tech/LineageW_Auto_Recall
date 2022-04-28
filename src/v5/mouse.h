#ifndef MOUSE_H
#define MOUSE_H

class Mouse{
public:
    Mouse();
    ~Mouse();
    void reset_mouse();
    void move(int8_t, int8_t, int);
    void click(uint8_t);
    void wheel(uint8_t);
private:
    struct {
        uint8_t buttons;
        int8_t x;
        int8_t y;
        int8_t wheel;   /* Not yet implemented */
    } mouseReport;
    uint8_t nullReport[4] = { 0, 0, 0, 0 };
};

#endif