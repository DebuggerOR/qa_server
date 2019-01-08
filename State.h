//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_STATE_H
#define PROJ2222_STATE_H


template <class T>
class State {
    T state;
    double cost;
    State<T> cameFrom;

public:
    State(T state);

    bool equals(State<T> s);

    int operator<(State state);

    double getCost();

    State<T> getCameFrom();

    T getState();
};



#endif //PROJ2222_STATE_H
