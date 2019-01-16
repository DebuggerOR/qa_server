

#include "MyClientHandler.h"
#include "MatrixCreator.h"
#include "Solver.h"
#include "BFS.h"
#include "Utils.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "CacheManagers.h"


void MyClientHandler::handleClient(string question, string &answer) {
    if (this->cm->isSavedSolution(question)) {
        answer = this->cm->getSolution(question);
    } else {
        MatrixCreator matrixCreator;
        Matrix *matrix = matrixCreator.createFromString(question);

        Searcher<Point *> *aStar = new AStar<Point *>;
        this->solver->setSolverImp(aStar);

        list<State<Point *> *> *traceAStar = this->solver->solve(matrix);
        delete aStar;

        if(traceAStar == nullptr){
            answer="-1";
        } else {
            vector<Point *> vec;
            for (auto &l:(*traceAStar)) {
                vec.push_back(l->getState());
            }

            Utils utils;
            answer = utils.pointsToString(vec);
            delete traceAStar;
        }

        delete matrix;

        this->cm->saveSolution(question, answer);
    }
}

MyClientHandler::MyClientHandler(CacheManager<string, string> *cm,
                                 Solver<list<State<Point *> *> *, Searchable<Point *> *> *solver) {
    this->cm = cm;
    this->solver = solver;
}

