#include <ScoreDisplay.h>

TM1637Display ScoreDisplay::display(SCORE_DP_CLK, SCORE_DP_DIO);
bool ScoreDisplay::isOn = true;

void ScoreDisplay::setup() {
    display.setBrightness(7);
    display.showNumberDec(DEFAULT_SCORE);
}

void ScoreDisplay::update() {
    if (GlobalState::score->hasChanged()) {
        info("Update score display : %d", GlobalState::score->get());
        display.showNumberDec(GlobalState::score->get());
    }

    if (GlobalState::remoteConnected->hasChanged() && !GlobalState::remoteConnected->get()) {
        isOn = false;
        info("Blinking score display");
        Timing::every(
            BLINK_INTERVAL,
            +[](void* _) -> bool{
                isOn = !isOn;
                return true;
            });
    }

    if (isOn) {
        display.setBrightness(7);
    } else {
        display.setBrightness(0);
    }
}