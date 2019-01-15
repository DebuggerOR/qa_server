

#ifndef PROJ2222_MYSERIALSERVER_H
#define PROJ2222_MYSERIALSERVER_H


#include "Server.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManagers.h"
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

void open(ClientHandler *clientHandler, int new_sock) {
    cout << "start server" << endl;
    string nextBuffer, connectedBuffer;
    char buffer[4096];

    try {
        while(true) {
            cout << buffer;
            bzero(buffer, 256);
            read(new_sock, buffer, 255);
            connectedBuffer += buffer;
            if (connectedBuffer[connectedBuffer.size() - 1] != '$') {
                connectedBuffer += "$";
            }
            if (!strcmp(buffer, "end")) {
                string answer;
                if(connectedBuffer[0]=='$'){
                    connectedBuffer[0]=' ';
                }
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
    cout << "end server" << endl;
}

void openSerial(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    bool isFirst=true;

    timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    bind(s, (sockaddr *) &serv, sizeof(serv));
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    while (!serialStop) {
        try {

            int new_sock;
            listen(s, 20000);
            struct sockaddr_in client;
            socklen_t clilen = sizeof(client);

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
                thread* t = new thread(open, clientHandler, new_sock);
                t->join();
                isFirst = false;
            }
        } catch (...) {
            cout << "connection with client stopped" << endl;
        }
    }
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

    listen(s, 20000);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    while (!parallelStop) {
        try {
            int new_sock;

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
                threads.push(new thread(open, clientHandler, new_sock));
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
