#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Display {
    public:
        static Display& getInstance();

        void setup();
        void print(String msg);

        // Make singleton
        Display(const Display&) = delete;
        Display& operator=(const Display&) = delete;
    private:
        Display();

        LiquidCrystal_I2C lcd;
};

#endif