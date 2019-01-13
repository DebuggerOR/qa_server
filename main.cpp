#include <iostream>
#include "MatrixCreator.h"
#include "Solver.h"
#include "DFS.h"
#include "BFS.h"
#include "Utils.h"
#include "BestFirstSearch.h"
#include "MySerialServer.h"
#include "MatrixCreator.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"

int main(int argc, const char *argv[]) {
    ClientHandler* clientHandler = new MyClientHandler();

    server_side::Server* server = new MySerialServer();

    server->start(stoi(argv[1]), clientHandler);

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
                    server_side::Server *server = new MySerialServer;

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