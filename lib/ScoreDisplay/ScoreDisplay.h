#ifndef __SCOREDISPLAY_H__
#define __SCOREDISPLAY_H__

#include <Arduino.h>
#include <RobotSettings.h>
#include <TM1637Display.h>
#include <arduino-timer.h>

class ScoreDisplay {
    public:
        static ScoreDisplay& getInstance();

        void setup();
        void update();
        
        
        // Make singleton
        ScoreDisplay(const ScoreDisplay&) = delete;
        ScoreDisplay& operator=(const ScoreDisplay&) = delete;
        private:
        bool on;
        
        Timer<1, millis, ScoreDisplay*> timer;
        TM1637Display display;

        void updateScore();
        void updateBlink();
        static bool blink(ScoreDisplay* self);

        ScoreDisplay();
};

#endif