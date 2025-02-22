#include <DynamicState.h>
#include <Arduino.h>
#include <RemoteData.h>
#include <RobotSettings.h>

#ifndef __GLOBAL_STATE_H__
#define __GLOBAL_STATE_H__

struct Travel {
    char forward;
    char lateral;
    char yaw;
};

class GlobalState{
    public:
        static GlobalState& getInstance();

        void updateFromController(RemoteData data);

        DynamicState<PositionName> position;
        DynamicState<byte> score;
        DynamicState<Travel> travel;
        DynamicState<float> speedFactor;
        DynamicState<bool> remoteConnected;

        // make singleton
        GlobalState(const GlobalState&) = delete;
        GlobalState& operator=(const GlobalState&) = delete;
    private:
        GlobalState();
};

#endif