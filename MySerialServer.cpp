//
// Created by ori on 1/6/19.
//

#include "MySerialServer.h"

bool shouldStop;

void open(ClientHandler *clientHandler, int port) {
    int rate = 10;
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // prepare the sockaddr_in structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // bind
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // listen
    listen(sockfd, rate);
    clilen = sizeof(cli_addr);

    // accept connection from an incoming client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // if connection is established then start communicating
    while (!shouldStop) {
        sleep(1 / rate);
        bzero(buffer, 256);
        read(newsockfd, buffer, 255);

        //TODO HOW???? HOW??? HOW CAN I HANDLE HERE THE CLIENT???
        //clientHandler->handleClient(buffer, );


        cout << buffer << endl;
    }
}

void MySerialServer::stop() {
    shouldStop = true;
}

void MySerialServer::start(int port, ClientHandler *clientHandler) {
    shouldStop = false;
    new thread(open, clientHandler, port);
}