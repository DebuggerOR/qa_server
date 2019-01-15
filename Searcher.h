//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


#include <iostream>
#include <queue>
#include "Solver.h"
#include "Searchable.h"
#include "SolverImp.h"


template <class T>
class Searcher : public SolverImp<list<State<T>*>*, Searchable<T>*> {
protected:
    int evaluatedNodes;

public:
    Searcher();
    virtual list<State<T>*>* search(Searchable<T>* searchable);
    int getNumberOfNodesEvaluated();
    list<State<T>*>* solveImp(Searchable<T>* searchable) override;

protected:
    list<State<T> *> *backTrace(State<T> *state, Searchable<T> *searchable);
};

template <class T>
int Searcher<T>::getNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}

template <class T>
Searcher<T>::Searcher() {
    this->evaluatedNodes=0;
}

template<class T>
list<State<T>*>* Searcher<T>::solveImp(Searchable<T>* searchable) {
    return this->search(searchable);
}

template<class T>
list<State<T> *> *Searcher<T>::search(Searchable<T> *searchable) {
    return nullptr;
}

template<class T>
list<State<T> *> *Searcher<T>::backTrace(State<T> *state, Searchable<T> *searchable) {
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


#endif //PROJ2222_SEARCHER_H
