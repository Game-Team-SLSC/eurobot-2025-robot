#include <GlobalState.h>
#include <RobotSettings.h>

GlobalState::GlobalState() : 
    position(FOLDED),
    score(DEFAULT_SCORE),
    travel({0, 0, 0}),
    speedFactor(1),
    remoteConnected(false)
    {}

<<<<<<< Updated upstream
GlobalState& GlobalState::getInstance() {
    static GlobalState instance;
    return instance;
}

void GlobalState::updateFromController(RemoteData data) {
    // TODO
=======
void GlobalState::updateFromController(RemoteData& remoteData) {

    score->set(remoteData.score);
    travel->set(Travel{
        remoteData.joystickLeft.x,
        abs(remoteData.joystickLeft.y) > abs(remoteData.joystickLeft.x) ? remoteData.joystickLeft.y :remoteData.joystickRight.y,
        remoteData.joystickRight.x
    });
    speedFactor->set(remoteData.slider / 255.f);
    isRightSide->set(remoteData.sw == UP);
>>>>>>> Stashed changes
}