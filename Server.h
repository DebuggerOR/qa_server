


#ifndef PROJ2222_SERVER_H
#define PROJ2222_SERVER_H


#include "ClientHandler.h"
#include "MySerialServer.h"

namespace server_side {
    class Server {

    public:
        virtual void start(int port, ClientHandler *c);

        virtual void stop();
    };

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


#endif //PROJ2222_SERVER_H
