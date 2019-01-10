//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


#include "Solver.h"
#include "Searchable.h"
#include "SolverImp.h"


template <class T>
class Searcher : public SolverImp<int,Searchable<T>> {
protected:
    int evlaluatedNodes;

public:
    Searcher();
    virtual void search(Searchable<T> searchable);
    int getNumberOfNodesEvaluated();
    int solveImp(Searchable<T> searchable);
};

template <class T>
int Searcher<T>::getNumberOfNodesEvaluated() {
    return this->evlaluatedNodes;
}

template <class T>
Searcher<T>::Searcher() {
    this->evlaluatedNodes=0;
}

template<class T>
int Searcher<T>::solveImp(Searchable<T> searchable) {
    return this->evlaluatedNodes;
}


#endif //PROJ2222_SEARCHER_H
