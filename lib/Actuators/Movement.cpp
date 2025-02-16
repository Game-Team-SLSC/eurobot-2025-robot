#include <Movement.h>

Movement::Movement(MovementCallback onStateChange): state(false) {
    callback = onStateChange;
};

bool Movement::getState() const {
    return state;
};

void Movement::setState(bool state) {
    this->state = state;
    callback(state);
};