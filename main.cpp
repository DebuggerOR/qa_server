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
    std::cout << "Hello, World!" << std::endl;

    ClientHandler* clientHandler = new MyClientHandler();

    server_side::Server* server = new MyParallelServer();

    server->start(stoi(argv[1]), clientHandler);

    return 0;
}
