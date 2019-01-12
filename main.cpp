#include <iostream>
#include "MatrixCreator.h"
#include "Solver.h"
#include "DFS.h"
#include "BFS.h"
#include "Utils.h"
//#include "MySerialServer.h"
//#include "MatrixCreator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto * matrixCreator = new MatrixCreator;
    Matrix* matrix = matrixCreator->createFromConsole();
    matrix->displayMat();

    auto * solver = new Solver<list<State<string>*>*, Searchable<string>*>;
    solver->setSolverImp(new BFS<string>);
    list<State<string>*>* lst = solver->solve(matrix);
    vector<string> vec;
    for (auto &l:(*lst)) {
        vec.push_back(l->getState());
    }
    Utils utils;
    cout<<utils.coordinatesToString(vec)<<endl;

    int x;
    cin>>x;

    return 0;
}

//
//namespace boot {
//
//    class Main {
//
//    public:
//        int main(int argc, const char * argv[]) {
//            // if get arguments
//            if(argc>1){
////                // server
////                Server* server = new MySerialServer;
////
////                // cache manager
////                CacheManager<string,string>* cacheManager = new FileCacheManager<string,string>;
////
//////                // solver
//////                Solver solver(new StringReverser);
////
//////                // client handler
//////                ClientHandler* clientHandler = new MyTestClientHandler<string,string>(cacheManager, solver);
////
//////                // start server
//////                server->start(stoi(argv[0]), clientHandler);
////            }
//
//            std::cout << "Hello, World!" << std::endl;
//
//            return 0;
//
//        }
//   // };
//}