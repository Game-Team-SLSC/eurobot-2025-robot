#include <Position.h>

Position::Position(MovementSet moves[]){
    moveCalls = moves;
};

void Position::set(){
    for (unsigned char i = 0; i < sizeof(moveCalls); ++i) {
        moveCalls[i].movement.setState(moveCalls[i].state);
    }
};