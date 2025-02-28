#ifndef __JOYSTICK_DATA_H__
#define __JOYSTICK_DATA_H__

#include <Arduino.h>

struct JoystickData {
    byte x; // - 128 to 127
    byte y; // - 128 to 127
    bool sw; // true if pressed

    bool operator==(const JoystickData &other) {
        return x == other.x && y == other.y && sw == other.sw;
    }
};

#endif