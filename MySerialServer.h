//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_MYSERIALSERVER_H
#define PROJ2222_MYSERIALSERVER_H


#include "Server.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include <thread>
#include <netinet/in.h>
#include <vector>
#include <strings.h>
#include <unistd.h>
#include <iostream>

//using namespace server_side;

class MySerialServer : public server_side::Server {

public:
    MySerialServer()= default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler);
};


#endif //PROJ2222_MYSERIALSERVER_H
