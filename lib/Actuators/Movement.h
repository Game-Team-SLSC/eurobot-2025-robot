#ifndef  __MOVEMENT_H__
#define __MOVEMENT_H__

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