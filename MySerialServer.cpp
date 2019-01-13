//
// Created by ori on 1/6/19.
//

#include "MySerialServer.h"

bool shouldStop;

void open(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
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
    if (new_sock < 0) {
        if (errno == EWOULDBLOCK) {
            cout << "timeout!" << endl;
            exit(2);
        } else {
            perror("other error");
            exit(3);
        }
    }
    cout << new_sock << endl;
    cout << s << endl;
    close(new_sock);
    close(s);
}

void MySerialServer::stop() {
    shouldStop = true;
}

void MySerialServer::start(int port, ClientHandler *clientHandler) {
    shouldStop = false;
    new thread(open, clientHandler, port);
}