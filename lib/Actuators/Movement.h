#ifndef  __MOVEMENT_H__
#define __MOVEMENT_H__

enum MOVEMENT_NAME {
    MAGNET_ATTACH,

    ARM_DEPLOY,

    GRABBER_CATCH,

    SUCTION_DEPLOY,

    GRABBER_BLOCK_UP,

    SUCTION_BLOCK_UP,

    PUMP_ENABLE,

    _MOVCOUNT
};;

using MovementCallback = void (*)(bool);

class Movement {
    public:
        Movement(MovementCallback onStateChange);
        void setState(bool state);
        bool getState() const;
    private:
        MovementCallback callback;
        bool state;
};

#endif