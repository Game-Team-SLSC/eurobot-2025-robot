#ifndef __ACTUATORS_H__
#define __ACTUATORS_H__

#include <Arduino.h>

#include <Adafruit_PWMServoDriver.h>
#include <Movement.h>
#include <Position.h>
#include <RobotSettings.h>
#include <TMCStepper.h>
#include <AccelStepper.h>

class Actuators {
    public:
        static Actuators& getInstance();

        void setup();

        void setPosition(PositionName pos);
        void releaseBanner();

        // Make singleton
        Actuators(const Actuators&) = delete;
        Actuators& operator=(const Actuators&) = delete;
    private:
        Actuators();

        Position* positions;

        void setMagnets(bool attaching);
        void setArms(bool deployed);
        void setGrabbers(bool catching);
        void setSuction(bool deployed);
        void setPumps(bool enabled);
        void moveGRBBlock(bool up);
        void moveSUCBlock(bool up);

        short getUSFromAngle(byte angle, boolean ccw = false);

        boolean pumpEnabled;

        Adafruit_PWMServoDriver pwm;

        TMC2209Stepper grbDriver, sucDriver;
        AccelStepper grbStepper, sucStepper;
};

#endif