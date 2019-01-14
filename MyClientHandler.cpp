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


void MyClientHandler::handleClient(string &question, string &answer) {
    cout<<question<<endl;

    MatrixCreator matrixCreator;
    Matrix* matrix = matrixCreator.createFromString(question);

    Searcher<Point*>* bfs = new BFS<Point*>;
    auto * solver = new Solver<list<State<Point*>*>*, Searchable<Point*>*>;
    solver->setSolverImp(bfs);

    list<State<Point*>*>* traceBFS=solver->solve(matrix);

    vector<Point*> vec;
    for (auto &l:(*traceBFS)) {
        vec.push_back(l->getState());
    }

    Utils utils;
    answer = utils.pointsToString(vec);
}
