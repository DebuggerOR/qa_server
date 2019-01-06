//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SEARCHER_H
#define PROJ2222_SEARCHER_H


#include "Solver.h"
#include "Searchable.h"

template <class Problem, class Solution, class T>
class Searcher : public Solver<Problem, Solution> {

public:
    void search(Searchable<T> searchable);
};


#endif //PROJ2222_SEARCHER_H
