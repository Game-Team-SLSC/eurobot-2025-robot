#ifndef __POSITION_H__
#define __POSITION_H__

#include <Movement.h>

struct MovementSet {
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