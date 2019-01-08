//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


#include "Solver.h"
#include "Searchable.h"

template <class T, class Solution>
class Searcher {
    int evlaluatedNodes;

public:
    Searcher();
    virtual Solution search(Searchable<T> searchable);
    int getNumberOfNodesEvaluated();
};

template <class T, class Solution>
int Searcher<T, Solution>::getNumberOfNodesEvaluated() {
    return this->evlaluatedNodes;
}

template <class T, class Solution>
Searcher<T, Solution>::Searcher() {
    this->evlaluatedNodes=0;
}


#endif //PROJ2222_SEARCHER_H
