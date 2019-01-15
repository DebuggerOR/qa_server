

#ifndef PROJ2222_DFS_H
#define PROJ2222_DFS_H


#include <iostream>
#include <map>
#include "Searcher.h"

template <class T>
class DFS : public Searcher<T>{

public:
    list<State<T>*>* search(Searchable<T>* searchable);

private:
    list<State<T>*>* visit(State<T> *state, map<State<T>*,char>* color, Searchable<T>* searchable);
};


template<class T>
list<State<T>*>* DFS<T>::search(Searchable<T>* searchable) {
    this->evaluatedNodes=0;
    map<State<T>*,char>* color;

    return this->visit(searchable->getInitialState(), color, searchable);
}

template<class T>
list<State<T> *> *
DFS<T>::visit(State<T> *state, map<State<T>*,char>* color, Searchable<T> *searchable) {
    ++this->evaluatedNodes;

    // if state is goal state
    if(searchable->getGoalState() == state){
        return this->backTrace(state, searchable);
    }

    list<State<T>*>* adj =  searchable->getAllPossibleStates(state);
    color->insert(pair<State<T>*,char>(state,'g'));

    for(auto &a : *adj) {
        // white iff not marked
        if(!color->count(a)) {
            a->setCameFrom(state);
            return this->visit(a, color, searchable);
        }
    }
    color->at(state)='b';
}


#endif //PROJ2222_DFS_H
