#ifndef __JOYSTICK_DATA_H__
#define __JOYSTICK_DATA_H__

#include <Arduino.h>

struct JoystickData {
    byte x;
    byte y;
    bool sw;

    bool operator==(const JoystickData &other) {
        return x == other.x && y == other.y && sw == other.sw;
    }
};

#endif