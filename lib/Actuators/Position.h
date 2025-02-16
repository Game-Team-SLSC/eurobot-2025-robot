#ifndef __POSITION_H__
#define __POSITION_H__

#include <Movement.h>

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

using MovementSet = struct {
    Movement movement;
    bool state;
};

class Position {
    public:
        Position(MovementSet moves[]);
        void set();
    private:
        MovementSet* moveCalls;
};

#endif