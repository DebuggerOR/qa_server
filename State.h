//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_STATE_H
#define PROJ2222_STATE_H


template <class T>
class State {
    T state;
    double cost;
    State<T>* cameFrom;

public:
    bool equals(State<T>* s);

    int operator<(State state);

    double getCost();

    State<T>* getCameFrom();

    void setCost(T cost);

    void setCameFrom(State<T>* state);

    T getState();
};

template<class T>
bool State<T>::equals(State<T>* state) {
    return this->state = state->state;
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
State<T>* State<T>::getCameFrom() {
    return this->cameFrom;
}

template<class T>
void State<T>::setCameFrom(State<T>* state) {
    this->cameFrom=state;
}

template<class T>
void State<T>::setCost(T cost) {
    this->cost=cost;
}




#endif //PROJ2222_STATE_H
