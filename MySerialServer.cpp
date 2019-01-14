//
// Created by ori on 1/6/19.
//

#include <cstring>
#include "MySerialServer.h"


bool serialStop;

void open(ClientHandler *clientHandler, int port) {
    cout << "start server at port " << port << endl;
    bool isFirst=true;
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
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    new_sock = accept(s, (struct sockaddr *) &client, &clilen);
    try {
        while (!serialStop) {
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
                        serialStop=true;
                    } else {
                        perror("other error");
                        serialStop=true;
                    }
                }
            }
        }
    } catch (...) {
        cout<<"connection stopped"<<endl;
    }
    close(new_sock);
    close(s);
}

void MySerialServer::stop() {
    serialStop = true;
}

void MySerialServer::start(int port, ClientHandler *clientHandler) {
    serialStop = false;
    thread* t = new thread(open, clientHandler, port);
    t->join();
}