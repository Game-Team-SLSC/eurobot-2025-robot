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
        void update();
    private:
        T value;
        bool changed;
};

template <typename T>
DynamicState<T>::DynamicState(T v) {
  changed = false;
  value = v;
}

template <typename T>
T DynamicState<T>::get() {
  return value;
}

template <typename T>
void DynamicState<T>::set(T v) {
  if (value == v) return;
  
  value = v;
  changed = true;
}

template <typename T>
bool DynamicState<T>::hasChanged() {
  return changed;
}

template <typename T>
void DynamicState<T>::update() {
  changed = false;
}

#endif