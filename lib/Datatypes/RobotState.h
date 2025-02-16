#ifndef __ROBOT_STATE_H__
#define __ROBOT_STATE_H__

#include <Arduino.h>

class RobotState {
private:
    // Private constructor to prevent instantiation
    RobotState() = delete;

public:
    // Static members
    static bool armsDeployed;
    static bool sideCansReleased;
    static bool magnetAttaching;

};

#endif