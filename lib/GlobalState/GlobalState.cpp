#include <GlobalState.h>
#include <RobotSettings.h>

GlobalState::GlobalState() : 
    position(FOLDED),
    score(DEFAULT_SCORE),
    travel({0, 0, 0}),
    speedFactor(1),
    remoteConnected(false)
    {}

GlobalState& GlobalState::getInstance() {
    static GlobalState instance;
    return instance;
}

void GlobalState::updateFromController(RemoteData data) {
    // TODO
}