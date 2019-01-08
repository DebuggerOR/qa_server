


#include "State.h"

template<class T>
State<T>::State(T state) {
    this->state = state;
}

template<class T>
bool State<T>::equals(State<T> s) {
    return this->state = s.state;
}

template<class T>
int State<T>::operator<(State state) {
    return static_cast<int>(this->cost - state.getCost());
}

template<class T>
double State<T>::getCost() {
    return this->cost;
}

template<class T>
T State<T>::getState() {
    return this->state;
}

template<class T>
State<T> State<T>::getCameFrom() {
    return this->cameFrom;
}

template<class T>
void State<T>::setCameFrom(State<T> state) {
    this->cameFrom=state;
}
