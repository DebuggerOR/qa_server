#include <iostream>
#include "MatrixCreator.h"
#include "Solver.h"
#include "DFS.h"
#include "BFS.h"
#include "Utils.h"
#include "BestFirstSearch.h"
#include "MyServers.h"
#include "MatrixCreator.h"
#include "MyServers.h"
#include "MyClientHandler.h"
#include "AStar.h"

void testConsole() {
    Utils utils;
    MatrixCreator matrixCreator;
    Matrix *matrix = matrixCreator.createFromConsole();

    matrix->displayMat();
    list<State<Point *> *> *lst;
    vector<Point *> vec;
    auto *solver = new Solver<list<State<Point *> *> *, Searchable<Point *> *>;

    cout << "\ntest dfs\n" << endl;

    auto *dfs = new DFS<Point *>;
    solver->setSolverImp(dfs);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << dfs->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest bfs\n" << endl;

    auto *bfs = new BFS<Point *>;
    solver->setSolverImp(bfs);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << bfs->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest best\n" << endl;

    auto *best = new BestFirstSearch<Point *>;
    solver->setSolverImp(best);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << best->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest a star\n" << endl;

    auto *a = new AStar<Point *>;
    solver->setSolverImp(a);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << a->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    delete dfs;
    delete bfs;
    delete best;
    delete a;
    delete solver;
    delete matrix;
}

void testFile(string name) {
    Utils utils;
    MatrixCreator matrixCreator;
    Matrix *matrix = matrixCreator.createFromFile(name);

    matrix->displayMat();
    list<State<Point *> *> *lst;
    vector<Point *> vec;
    auto *solver = new Solver<list<State<Point *> *> *, Searchable<Point *> *>;

    cout << "\ntest dfs\n" << endl;

    auto *dfs = new DFS<Point *>;
    solver->setSolverImp(dfs);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << dfs->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest bfs\n" << endl;

    auto *bfs = new BFS<Point *>;
    solver->setSolverImp(bfs);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << bfs->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest best\n" << endl;

    auto *best = new BestFirstSearch<Point *>;
    solver->setSolverImp(best);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << best->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    cout << "\ntest a star\n" << endl;

    auto *a = new AStar<Point *>;
    solver->setSolverImp(a);
    lst = solver->solve(matrix);
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    cout << utils.pointsToString(vec) << endl;
    cout << "visited:\t" << a->getNumberOfNodesEvaluated() << endl;
    cout << "weight:\t" << utils.pathWeight(lst) << endl;
    vec.clear();
    delete lst;

    delete dfs;
    delete bfs;
    delete best;
    delete a;
    delete solver;
    delete matrix;
}

void testSerialServer(int port) {
    auto *cm = new FileCacheManager<string, string>;

    auto *solver = new Solver<list<State<Point *> *> *, Searchable<Point *> *>;

    ClientHandler *clientHandler = new MyClientHandler(cm, solver);

    server_side::Server *server = new MySerialServer();

    server->start(port, clientHandler);

    delete cm;
    delete solver;
    delete clientHandler;
    delete server;
}

void testParallelServer(int port) {
    auto *cm = new FileCacheManager<string, string>;

    auto *solver = new Solver<list<State<Point *> *> *, Searchable<Point *> *>;

    ClientHandler *clientHandler = new MyClientHandler(cm, solver);

    server_side::Server *server = new MyParallelServer();

    server->start(port, clientHandler);

    delete cm;
    delete solver;
    delete clientHandler;
    delete server;
}


int main(int argc, const char *argv[]) {

    //testConsole();

    //testFile("graphs50.txt");

    //testSerialServer(stoi(argv[1]));

    testParallelServer(stoi(argv[1]));

    return 0;
}




