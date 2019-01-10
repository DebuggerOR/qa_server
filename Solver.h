//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SOLVER_H
#define PROJ2222_SOLVER_H


#include "SolverImp.h"

template <class Solution ,class Problem>
class Solver {
    SolverImp<Solution, Problem>* solverImp;

public:
    Solver(SolverImp<Solution, Problem>* solverImp);

    virtual Solution solve(Problem);
};

template<class Solution, class Problem>
Solver<Solution, Problem>::Solver(SolverImp<Solution, Problem>* solverImp) {
    this->solverImp=solverImp;
}

template<class Solution, class Problem>
Solution Solver<Solution, Problem>::solve(Problem problem) {
    return this->solverImp.solveImp(problem);
}


#endif //PROJ2222_SOLVER_H
