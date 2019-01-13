//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_MYPARALLELSERVER_H
#define PROJ2222_MYPARALLELSERVER_H


#include "Server.h"
#include "ClientHandler.h"

//using namespace server_side;

class MyParallelServer : public server_side::Server {

public:
    MyParallelServer()= default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler);
};


#endif //PROJ2222_MYPARALLELSERVER_H
