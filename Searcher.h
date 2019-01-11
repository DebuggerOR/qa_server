//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


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
};

template <class T>
int Searcher<T>::getNumberOfNodesEvaluated() {
    return this->evlaluatedNodes;
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


#endif //PROJ2222_SEARCHER_H
