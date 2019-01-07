//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


#include "Solver.h"
#include "Searchable.h"

template <class T>
class Searcher {

public:
    virtual T search(Searchable<T> searchable);
    int getNumberOfNodesEvaluated();
};


#endif //PROJ2222_SEARCHER_H
