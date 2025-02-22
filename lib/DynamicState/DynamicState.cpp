#include <DynamicState.h>

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
bool DynamicState<T>::update() {
  changed = false;
}