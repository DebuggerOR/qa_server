#include <iostream>
#include "MatrixCreator.h"
#include "Solver.h"
#include "DFS.h"
#include "BFS.h"
//#include "MySerialServer.h"
//#include "MatrixCreator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto * matrixCreator = new MatrixCreator;
    Matrix* matrix = matrixCreator->createFromConsole();
    matrix->displayMat();

    auto * solver = new Solver<list<State<int>*>*, Searchable<int>*>;
    solver->setSolverImp(new BFS<int>);
    list<State<int>*>* list = solver->solve(matrix);
    for(auto &l : (*list)){
        cout<<l->getCost()<<"<-";
    }


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