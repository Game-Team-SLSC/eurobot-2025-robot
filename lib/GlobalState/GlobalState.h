#include <DynamicState.h>
#include <Arduino.h>
#include <RemoteData.h>

#ifndef __GLOBAL_STATE_H__
#define __GLOBAL_STATE_H__

enum PositionName {
    FOLDED,
    APPROACH,
    TRANSPORT,
    RELEASE,
    LATERAL,
    CATCH,
    S1,
    S2,
    _POSCOUNT
};

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
        DynamicState<float> speedFactor;
        DynamicState<Travel> travel;
        DynamicState<bool> remoteConnected;

        // make singleton
        GlobalState(const GlobalState&) = delete;
        GlobalState& operator=(const GlobalState&) = delete;
    private:
        GlobalState();
};

#endif