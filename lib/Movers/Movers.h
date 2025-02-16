#ifndef __MOVERS_H__
#define __MOVERS_H__

#include <Arduino.h>
#include <RobotSettings.h>
#include <Sabertooth.h>
#include <JoystickData.h>

class Movers {
    public:
        static Movers& getInstance();

        void setup();
        void drive(byte x, byte y, byte z); // x: lateral, y: forward, z: yaw
        void setSpeed(byte value);

        // Make singleton
        Movers(const Movers&) = delete;
        Movers& operator=(const Movers&) = delete;
    private:
        Movers();

        float speedRatio;
        Sabertooth saberFront, saberBack;
};

#endif