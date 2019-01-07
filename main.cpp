#include <iostream>
#include "MySerialServer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


namespace boot {

    class Main {

    public:
        int main(int argc, const char * argv[]) {
            // if get arguments
            if(argc>1){
                // server
                Server* server = new MySerialServer;

                // cache manager
                CacheManager<string,string>* cacheManager = new FileCacheManager<string,string>;

                // solver
                Solver<string,string>* solver = new StringReverser;

                // client handler
                ClientHandler* clientHandler = new MyTestClientHandler<string,string>(cacheManager, solver);

                // start server
                server->start(stoi(argv[0]), clientHandler);
            }

            std::cout << "Hello, World!" << std::endl;

            return 0;

        }
    };
}