


#ifndef PROJ2222_SEARCHABLE_H
#define PROJ2222_SEARCHABLE_H


#include "State.h"
#include "list"


using namespace std;

template <class T>
class Searchable {

public:
    State<T> getInitialState();
    State<T> getGoalState();
    list<State<T>> getAllPossibleStates(State<T> s);
    list<State<T>> getAllStates();
};


#endif //PROJ2222_SEARCHABLE_H
