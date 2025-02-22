#ifndef __DYNAMIC_STATE_H__
#define __DYNAMIC_STATE_H__
#pragma once

template <typename T>
class DynamicState {
    public:
        DynamicState(T v);

        T get();
        void set(T value);

        bool hasChanged();
        bool update();
    private:
        T value;
        bool changed;
};

#endif