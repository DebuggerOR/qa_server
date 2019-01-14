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

void testConsole(){
    auto * matrixCreator = new MatrixCreator;
    Matrix* matrix = matrixCreator->createFromConsole();
    matrix->displayMat();

    auto * solver = new Solver<list<State<Point*>*>*, Searchable<Point*>*>;

//    solver->setSolverImp(new BFS<Point*>);
//    list<State<Point*>*>* lst = solver->solve(matrix);
//    vector<Point*> vec;
//    for (auto &l:(*lst)) {
//        vec.push_back(l->getState());
//    }
//    Utils utils;
//    cout<<utils.pointsToString(vec)<<endl;
//
//    solver->setSolverImp(new DFS<Point*>);
//    list<State<Point*>*>* lst1 = solver->solve(matrix);
//    vector<Point*> vec1;
//    for (auto &l:(*lst1)) {
//        vec1.push_back(l->getState());
//    }
//    cout<<utils.pointsToString(vec1)<<endl;
//
//    solver->setSolverImp(new BestFirstSearch<Point*>);
//    list<State<Point*>*>* lst2 = solver->solve(matrix);
//    vector<Point*> vec2;
//    for (auto &l:(*lst2)) {
//        vec2.push_back(l->getState());
//    }
//    cout<<utils.pointsToString(vec2)<<endl;


    Utils utils;
    solver->setSolverImp(new AStar<Point*>);
    list<State<Point*>*>* lst2 = solver->solve(matrix);
    vector<Point*> vec2;
    for (auto &l:(*lst2)) {
        vec2.push_back(l->getState());
    }
    cout<<utils.pointsToString(vec2)<<endl;
}

void testSerialServer(int port){
    ClientHandler* clientHandler = new MyClientHandler();

    server_side::Server* server = new MyServers();

    server->start(port, clientHandler);
}

void testParallelServer(int port){
    ClientHandler* clientHandler = new MyClientHandler();

    server_side::Server* server = new MyParallelServer();

    server->start(port, clientHandler);
}


int main(int argc, const char *argv[]) {
    testConsole();

    //testSerialServer(stoi(argv[1]));

    //testParallelServer(stoi(argv[1]));

    return 0;
}

namespace server_side {
    namespace boot {

        class Main {

        public:
            int main(int argc, const char *argv[]) {
                // if get arguments
                if (argc > 1) {
                    // server
                    server_side::Server *server = new MyServers;

                    // cache manager
                    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>;

                    // solver
                    Solver<string, string> *solver = new Solver<string, string>(new StringReverser);

                    // client handler
                    ClientHandler *clientHandler = new MyTestClientHandler<string, string>(cacheManager, solver);

                    // start server
                    server->start(stoi(argv[0]), clientHandler);
                }

                return 0;

            }
        };
    }
}