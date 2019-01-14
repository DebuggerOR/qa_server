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
#include <cstring>

using namespace server_side;

bool serialStop;
bool parallelStop;

void openSerial(ClientHandler *clientHandler, int port) {
    cout << "start server" << endl;
    bool isFirst=true;
    bool isTimeOutOther= false;
    string nextBuffer, connectedBuffer;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    char buffer[4096];
    if (bind(s, (sockaddr *) &serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }

    int new_sock;
    listen(s, 5);//TODO check if 1 works
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    new_sock = accept(s, (struct sockaddr *) &client, &clilen);
    try {
        while (!serialStop&&!isTimeOutOther) {
            cout<<buffer;
            bzero(buffer, 256);
            read(new_sock, buffer, 255);
            connectedBuffer+=buffer;
            if(connectedBuffer[connectedBuffer.size()-1]!='$') {
                connectedBuffer += "$";
            }
            if(!strcmp(buffer,"end")){
                string answer;
                clientHandler->handleClient(connectedBuffer,answer);
                const char *cstr = answer.c_str();
                write(new_sock, cstr, answer.size());
                connectedBuffer="";
                isFirst=false;
            }
            if(!isFirst) {
                if (new_sock < 0) {
                    if (errno == EWOULDBLOCK) {
                        cout << "timeout!" << endl;
                        isTimeOutOther=true;
                    } else {
                        perror("other error");
                        isTimeOutOther=true;
                    }
                }
            }
        }
    } catch (...) {
        cout<<"connection stopped"<<endl;
    }
    close(new_sock);
    close(s);
    cout << "end server" << endl;
}

void openSerialSocket(ClientHandler *clientHandler, int port, int new_sock, int s) {
    cout << "start server" << new_sock << endl;
    string nextBuffer, connectedBuffer;
    char buffer[4096];

    try {
        while(!parallelStop) {
            cout << buffer;
            bzero(buffer, 256);
            read(new_sock, buffer, 255);
            connectedBuffer += buffer;
            if (connectedBuffer[connectedBuffer.size() - 1] != '$') {
                connectedBuffer += "$";
            }
            if (!strcmp(buffer, "end")) {
                string answer;
                clientHandler->handleClient(connectedBuffer, answer);
                const char *cstr = answer.c_str();
                write(new_sock, cstr, answer.size());
                break;
            }
        }
    } catch (...) {
        cout << "connection stopped" << endl;
    }
    close(new_sock);
    close(s);
    cout << "end server" << new_sock << endl;
}

void openParallel(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    bool isFirst=true;
    queue<thread*> threads;

    bind(s, (sockaddr *) &serv, sizeof(serv));

    while (!parallelStop) {
        try {

            int new_sock;
            listen(s, 20000);
            struct sockaddr_in client;
            socklen_t clilen = sizeof(client);

            timeval timeout;
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;

            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
            new_sock = accept(s, (struct sockaddr *) &client, &clilen);

            if (!isFirst) {
                if (new_sock < 0) {
                    if (errno == EWOULDBLOCK) {
                        cout << "timeout!" << endl;
                        break;

                    } else {
                        perror("other error");
                        break;
                    }
                }
            }

            if(new_sock>=0) {
                threads.push(new thread(openSerialSocket, clientHandler, port, new_sock, s));
                isFirst = false;
            }
        } catch (...) {
            cout << "connection with client stopped" << endl;
        }
    }
    while (!threads.empty()){
        threads.front()->join();
        threads.pop();
    }
}

class MyServers : public Server {

public:
    MyServers()= default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler);
};


void MyServers::stop() {
    serialStop = true;
}

void MyServers::start(int port, ClientHandler *clientHandler) {
    serialStop = false;
    thread* t = new thread(openSerial, clientHandler, port);
    t->join();
}

class MyParallelServer : public server_side::Server {

public:
    MyParallelServer()= default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler) override;
};


void MyParallelServer::stop() {
    parallelStop = true;
}

void MyParallelServer::start(int port, ClientHandler *clientHandler) {
    parallelStop = false;
    thread* t = new thread(openParallel, clientHandler, port);
    t->join();
}



#endif //PROJ2222_MYSERIALSERVER_H
