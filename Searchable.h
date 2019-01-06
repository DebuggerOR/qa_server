//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHABLE_H
#define PROJ2222_SEARCHABLE_H


#include "State.h"
#include "list"

using namespace std;

template <class T>
class Searchable{

public:
    State<T> getInitialState();
    State<T> getGoalState();
    list<State<T>> getAllPossibleStates();
};

#endif //PROJ2222_SEARCHABLE_H
