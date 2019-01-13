//
// Created by ori on 1/6/19.
//

#include "MyParallelServer.h"

void MyParallelServer::stop() {
    Server::stop();
}

void MyParallelServer::start(int port, ClientHandler *clientHandler) {
    Server::start(port, clientHandler);
}
