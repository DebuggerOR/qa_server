//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_CLIENTHANDLER_H
#define PROJ2222_CLIENTHANDLER_H


#include <iostream>
#include <fstream>

using namespace std;

class ClientHandler {

public:
    virtual void handleClient();

    virtual void handleClient(int port);

    virtual void handleClient(string &question, string &answer);

    virtual void handleClient(istream in, ostream out);
};


#endif //PROJ2222_CLIENTHANDLER_H
