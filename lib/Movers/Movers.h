#ifndef __MOVERS_H__
#define __MOVERS_H__

#include <Arduino.h>
#include <RobotSettings.h>
#include <JoystickData.h>
#include <L298NX2.h>

class Movers {
    public:
        static Movers& getInstance();

        void setup();
        void update();

        // Make singleton
        Movers(const Movers&) = delete;
        Movers& operator=(const Movers&) = delete;
    private:
        Movers();
        
        L298NX2 frontDriver, rearDriver;
};

#endif