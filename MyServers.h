

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
#include <queue>
#include <list>


using namespace server_side;


bool serialStop;
bool parallelStop;


void serial(ClientHandler *clientHandler, int new_sock, bool *isTimeOut) {
    cout << "start" << endl;
    string nextBuffer, connectedBuffer;
    char buffer[4096];

    *isTimeOut = false;

    try {
        while (!serialStop) {
            bzero(buffer, 256);
            read(new_sock, buffer, 255);
            connectedBuffer += buffer;
            string strBuff(connectedBuffer);
            if (strBuff.find("end") != string::npos) {
                string answer;
                clientHandler->handleClient(connectedBuffer, answer);
                const char *cstr = answer.c_str();
                write(new_sock, cstr, answer.size());
                break;
            }
        }
    } catch (...) {
    }
    close(new_sock);
    cout << "stop" << endl;
}


void parallel(ClientHandler *clientHandler, int new_sock, bool *isRun) {
    cout << "start" << endl;
    string nextBuffer, connectedBuffer;
    char buffer[4096];
    string strBuff;

    *isRun = true;

    try {
        while (!parallelStop) {
            bzero(buffer, 256);
            read(new_sock, buffer, 255);
            connectedBuffer += buffer;
            string strBuff(connectedBuffer);
            if (strBuff.find("end")!=string::npos) {
                string answer;
                clientHandler->handleClient(connectedBuffer, answer);
                const char *cstr = answer.c_str();
                write(new_sock, cstr, answer.size());
                break;
            }
        }
    } catch (...) {
    }
    close(new_sock);
    *isRun = false;
    cout << "stop" << endl;
}


void openSerial(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    bool *isTimeOut = new bool;
    *isTimeOut = false;

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

            if (*isTimeOut) {
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

            if (new_sock >= 0) {
                thread *t = new thread(serial, clientHandler, new_sock, isTimeOut);
                t->join();
                delete t;
                *isTimeOut = true;
            }
        } catch (...) {
            cout << "connection with client stopped" << endl;
        }
    }
    delete isTimeOut;
}


void openParallel(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    queue<thread *> threads;
    list<bool *> isRunning;
    bool isFirst = true;

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

            bool isTimeOut = !isFirst;
            for (auto &r : isRunning) {
                if (*r) {
                    isTimeOut = false;
                    break;
                }
            }
            if (isTimeOut) {
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

            if (new_sock >= 0) {
                bool *isRun = new bool;
                isRunning.push_back(isRun);
                threads.push(new thread(parallel, clientHandler, new_sock, isRun));
                isFirst = false;
            }
        } catch (...) {
            cout << "connection with client stopped" << endl;
        }
    }
    while (!threads.empty()) {
        threads.front()->join();
        delete threads.front();
        threads.pop();
    }
    for (auto &i : isRunning) {
        delete i;
    }
}

class MySerialServer : public Server {

public:
    MySerialServer() = default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler);
};


void MySerialServer::stop() {
    serialStop = true;
}

void MySerialServer::start(int port, ClientHandler *clientHandler) {
    serialStop = false;
    thread *t = new thread(openSerial, clientHandler, port);
    t->join();
    delete t;
}

class MyParallelServer : public server_side::Server {

public:
    MyParallelServer() = default;

    void stop() override;

    void start(int port, ClientHandler *clientHandler) override;
};


void MyParallelServer::stop() {
    parallelStop = true;
}

void MyParallelServer::start(int port, ClientHandler *clientHandler) {
    parallelStop = false;
    thread *t = new thread(openParallel, clientHandler, port);
    t->join();
    delete t;
}


#endif //PROJ2222_MYSERIALSERVER_H
