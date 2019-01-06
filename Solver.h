//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_SOLVER_H
#define PROJ2222_SOLVER_H


template <class Solution ,class Problem>
class Solver{

public:
    virtual Solution solve(Problem);
};


#endif //PROJ2222_SOLVER_H
