#pragma once

#include <TM1637Display.h>
#include <Arduino.h>
#include <Timing.h>
#include <GlobalSettings.h>
#include <GlobalState.h>

class ScoreDisplay {
    public:

    static void setup();
    static void update();

    private:

    static byte shownScore;
    static bool isOn;
    static EveryTimer* timer;
    static TM1637Display display;
};