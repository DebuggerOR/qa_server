
#ifndef PROJ2222_SOLVER_H
#define PROJ2222_SOLVER_H


#include "SolverImp.h"

template<class Solution, class Problem>
class Solver {
    SolverImp<Solution, Problem> *solverImp;

public:
    Solver();

    Solver(SolverImp<Solution, Problem> *solverImp);

    virtual Solution solve(Problem);

    void setSolverImp(SolverImp<Solution, Problem> *solverImp);
};

template<class Solution, class Problem>
Solver<Solution, Problem>::Solver(SolverImp<Solution, Problem> *solverImp) {
    this->solverImp = solverImp;
}

template<class Solution, class Problem>
Solution Solver<Solution, Problem>::solve(Problem problem) {
    return this->solverImp->solveImp(problem);
}

template<class Solution, class Problem>
void Solver<Solution, Problem>::setSolverImp(SolverImp<Solution, Problem> *solverImp) {
    this->solverImp = solverImp;
}

template<class Solution, class Problem>
Solver<Solution, Problem>::Solver() {

}


#endif //PROJ2222_SOLVER_H
