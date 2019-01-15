//
// Created by ori on 1/13/19.
//

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
    auto * cacheManager = new FileCacheManager<string, string>;
    if (cacheManager->isSavedSolution(question)) {
        answer = cacheManager->getSolution(question);

    } else {
        MatrixCreator matrixCreator;
        Matrix *matrix = matrixCreator.createFromString(question);

        Searcher < Point * > *aStar = new AStar<Point *>;
        auto *solver = new Solver<list<State<Point *> *> *, Searchable<Point *> *>;
        solver->setSolverImp(aStar);

        list<State<Point *> *> *traceAStar = solver->solve(matrix);

        vector<Point *> vec;
        for (auto &l:(*traceAStar)) {
            vec.push_back(l->getState());
        }

        Utils utils;
        answer = utils.pointsToString(vec);
        cacheManager->saveSolution(question, answer);
    }

    delete cacheManager;
}
