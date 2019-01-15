//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_STRINGREVERSER_H
#define PROJ2222_STRINGREVERSER_H


#include <string>
#include "Solver.h"

//using namespace std;
//
//class StringReverser : public SolverImp<string, string> {
//
//public:
//    string solveImp(string problem);
//};

//namespace server_side {
//    namespace boot {
//
//        class Main {
//
//        public:
//            int main(int argc, const char *argv[]) {
//                // if get arguments
//                if (argc > 1) {
//                    // server
//                    server_side::Server *server = new MySerialServer;
//
//                    // cache manager
//                    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>;
//
//                    // solver
//                    Solver<string, string> *solver = new Solver<string, string>(new StringReverser);
//
//                    // client handler
//                    ClientHandler *clientHandler = new MyTestClientHandler<string, string>(cacheManager, solver);
//
//                    // start server
//                    server->start(stoi(argv[0]), clientHandler);
//                }
//
//                return 0;
//
//            }
//        };
//    }
//}


#endif //PROJ2222_STRINGREVERSER_H
