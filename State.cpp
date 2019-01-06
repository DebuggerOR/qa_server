//
// Created by ori on 1/6/19.
//

#include "State.h"

template<class T>
State<T>::State(T state) {
    this->state=state;
}

template<class T>
bool State<T>::equals(State<T> s) {
    return this->state=s.state;
}