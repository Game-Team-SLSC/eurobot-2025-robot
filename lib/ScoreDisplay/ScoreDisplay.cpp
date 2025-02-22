#include <ScoreDisplay.h>
#include <Arduino.h>
#include <RobotSettings.h>
#include <GlobalState.h>
#include <arduino-timer.h>

GlobalState& globalState = GlobalState::getInstance();

ScoreDisplay::ScoreDisplay() : display(SCORE_DP_CLK, SCORE_DP_DIO), timer() {
    on = true;
}

ScoreDisplay& ScoreDisplay::getInstance() {
    static ScoreDisplay instance;
    return instance;
}

void ScoreDisplay::setup() {
    display.setBrightness(7, true);
    display.showNumberDec(DEFAULT_SCORE);
}

void ScoreDisplay::update() {
    updateScore();
    updateBlink();
}

void ScoreDisplay::updateScore() {
    if (!globalState.score.hasChanged()) return;

    display.showNumberDec(globalState.score.get());
}

void ScoreDisplay::updateBlink() {
    if (!globalState.remoteConnected.hasChanged()) return;
    
    if (globalState.remoteConnected.get()) {
        timer.cancel();
        on = true;
        display.setBrightness(7);
    } else {
        timer.every(BLINK_INTERVAL, blink, this);
    }
}

bool ScoreDisplay::blink(ScoreDisplay* self) {
    if (globalState.remoteConnected.get()) return false;
    
    self->on = !self->on;

    if (self->on) {
        self->display.setBrightness(0);
    } else {
        self->display.setBrightness(7);
    }

    return true;
}