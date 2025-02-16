#ifndef __SCOREDISPLAY_H__
#define __SCOREDISPLAY_H__

#include <Arduino.h>
#include <RobotSettings.h>
#include <TM1637Display.h>

class ScoreDisplay {
    public:
        static ScoreDisplay& getInstance();

        void setup();
        void setScore(byte score);
        void updateBlink();
        
        bool blinking;

        // Make singleton
        ScoreDisplay(const ScoreDisplay&) = delete;
        ScoreDisplay& operator=(const ScoreDisplay&) = delete;
    private:
        TM1637Display display;
        byte lastScore;
        unsigned long lastBlink;

        ScoreDisplay();
};

#endif