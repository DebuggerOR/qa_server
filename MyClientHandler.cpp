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
    matrix->displayMat();//TODO


    Searcher<Point*>* bfs = new BFS<Point*>;
    Searcher<Point*>* dfs = new DFS<Point*>;
    Searcher<Point*>* best = new BestFirstSearch<Point*>;
    //Searcher<Point*>* as = new AStar<Point*>;


    auto * solver = new Solver<list<State<Point*>*>*, Searchable<Point*>*>;

    solver->setSolverImp(bfs);
    list<State<Point*>*>* traceBFS=solver->solve(matrix);

//    solver->setSolverImp(dfs);
//    list<State<Point*>*>* traceDFS=solver->solve(matrix);
//
//    solver->setSolverImp(best);
//    list<State<Point*>*>* traceBest=solver->solve(matrix);

    list<State<Point*>*>* traceMin=traceBFS;

//    if(traceBest->size()>traceDFS->size()){
//        traceMin=traceDFS;
//    }
//    if(traceDFS->size()>traceBest->size()){
//        traceMin=traceBest;
//    }

    vector<Point*> vec;
    for (auto &l:(*traceMin)) {
        vec.push_back(l->getState());
    }
    Utils utils;
    answer = utils.pointsToString(vec);
}
