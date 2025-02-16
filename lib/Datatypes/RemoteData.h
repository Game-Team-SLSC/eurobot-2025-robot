#ifndef __REMOTE_DATA_H__
#define __REMOTE_DATA_H__

#include <Arduino.h>
#include <JoystickData.h>

enum SWITCH_3_POS {UP, DOWN, MIDDLE};

struct RemoteData
{
    JoystickData joystickLeft;
    JoystickData joystickRight;

    bool buttons[10];
    byte slider;
    byte score;
    SWITCH_3_POS sw;

    bool operator==(const RemoteData &other) {
        return slider == other.slider &&
               score == other.score &&
               sw == other.sw &&
               joystickLeft == other.joystickLeft &&
               joystickRight == other.joystickRight &&
               memcmp(buttons, other.buttons, sizeof(buttons)) == 0;
    }
};

#endif