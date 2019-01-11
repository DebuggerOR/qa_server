


#ifndef PROJ2222_SEARCHABLE_H
#define PROJ2222_SEARCHABLE_H


#include "State.h"
#include "list"


using namespace std;

template <class T>
class Searchable {

public:
    virtual State<T>* getInitialState();
    virtual State<T>* getGoalState();
    virtual list<State<T>*>* getAllPossibleStates(State<T>* s);
};

template<class T>
State<T> *Searchable<T>::getInitialState() {
    return nullptr;
}

template<class T>
State<T> *Searchable<T>::getGoalState() {
    return nullptr;
}

template<class T>
list<State<T> *> *Searchable<T>::getAllPossibleStates(State<T> *s) {
    return nullptr;
}


#endif //PROJ2222_SEARCHABLE_H
