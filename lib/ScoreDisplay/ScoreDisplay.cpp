#include <ScoreDisplay.h>
#include <Arduino.h>
#include <RobotSettings.h>

ScoreDisplay::ScoreDisplay() : display(SCORE_DP_CLK, SCORE_DP_DIO) {
    lastScore = 0;
    blinking = false;
    lastBlink = 0;
}

ScoreDisplay& ScoreDisplay::getInstance() {
    static ScoreDisplay instance;
    return instance;
}

void ScoreDisplay::setup() {
    display.setBrightness(0x0a);
    display.showNumberDec(DEFAULT_SCORE);
}

void ScoreDisplay::updateBlink() {
    if (!blinking) {
        display.setBrightness(0x0);
        return;
    } 
    
    if (millis() - lastBlink < BLINK_INTERVAL) return;

    display.setBrightness(0x0a);
    lastBlink = millis();
}

void ScoreDisplay::setScore(byte score) {
    if (score == lastScore) return;
    
    display.showNumberDec(score);
    lastScore = score;
}