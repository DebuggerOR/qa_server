//
// Created by ori on 1/6/19.
//

#include "MyTestClientHandler.h"

template<class Solution, class Problem>
MyTestClientHandler<Solution, Problem>::MyTestClientHandler(CacheManager<Problem, Solution> *cm,
                                                            Solver<Problem, Solution> *solver) {
    this->solver=solver;
    this->cm=cm;
}

template<class Solution, class Problem>
void MyTestClientHandler<Solution, Problem>::handleClient(istream in, ostream out) {
    char buffer[256];
    in.getline(buffer, 256);


    while (buffer != "end") {
        if (this->cm->isSavedSolution(buffer)) {
            out << this->cm->getSolution(buffer)<< flush;
        } else {
            this->cm->saveSolution(buffer, solver->solve(buffer));
            out << this->cm->getSolution(buffer)<< flush;
        }
        in.getline(buffer, 256);
    }
}
