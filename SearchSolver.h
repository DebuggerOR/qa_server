//
// Created by ori on 1/7/19.
//

#ifndef PROJ2222_SEARCHSOLVER_H
#define PROJ2222_SEARCHSOLVER_H

#include "Solver.h"

template <class Problem, class Solution>
class SearchSolver : Solver<Problem, Solution> {
    Solution solve(Problem problem);

};

template<class Problem, class Solution>
Solution SearchSolver<Problem, Solution>::solve(Problem problem) {
    return nullptr;
}


#endif //PROJ2222_SEARCHSOLVER_H
