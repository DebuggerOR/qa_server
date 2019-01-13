

#ifndef PROJ2222_DFS_H
#define PROJ2222_DFS_H


#include <iostream>
#include "Searcher.h"

template <class T>
class DFS : public Searcher<T>{

public:
    list<State<T>*>* search(Searchable<T>* searchable);

private:
    list<State<T>*>* visit(State<T>* state, list<State<T>*> blacks, list<State<T>*> grays, Searchable<T>* searchable);
    list<State<T>*>* backTrace(State<T>* state, Searchable<T>* searchable);
};


/**
 * DFS according Corman
 */

template<class T>
list<State<T>*>* DFS<T>::search(Searchable<T>* searchable) {
    this->evaluatedNodes=1;
    list<State<T>*> blacks;
    list<State<T>*> grays;

    return this->visit(searchable->getInitialState(), blacks, grays, searchable);
}

template<class T>
list<State<T> *> *
DFS<T>::visit(State<T> *state, list<State<T> *> blacks, list<State<T> *> grays, Searchable<T> *searchable) {

    // if state is goal state
    if(searchable->getGoalState() == state){
        return this->backTrace(state, searchable);
    }

    list<State<T>*> adj =  *(searchable->getAllPossibleStates(state));
    grays.push_back(state);

    for(auto &a : adj) {
        bool isWhite = true;
        for (auto &g : grays) {
            if(a == g){
                isWhite= false;
            }
        }

        if(isWhite) {
            this->evaluatedNodes++;
            a->setCameFrom(state);
            return this->visit(a, blacks, grays, searchable);
        }
    }
    blacks.push_back(state);
}

template<class T>
list<State<T> *> *DFS<T>::backTrace(State<T> *state, Searchable<T> *searchable) {
    cout<<"DFS returns trace"<<endl;
    auto * trace = new list<State<T>*>;

    while (state != searchable->getInitialState()){
        if(state == nullptr){
            cout<<"no path"<<endl;
            return nullptr;
        }
        trace->push_back(state);
        state = state->getCameFrom();
    }
    trace->push_back(searchable->getInitialState());

    return trace;
}


#endif //PROJ2222_DFS_H
