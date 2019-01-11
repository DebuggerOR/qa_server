//
// Created by ori on 1/10/19.
//

#ifndef PROJ2222_SOLVERIMP_H
#define PROJ2222_SOLVERIMP_H


template <class Solution, class Problem>
class SolverImp {
public:
    virtual Solution solveImp(Problem problem);
};

template<class Solution, class Problem>
Solution SolverImp<Solution, Problem>::solveImp(Problem problem) {
    return nullptr;
}


#endif //PROJ2222_SOLVERIMP_H
