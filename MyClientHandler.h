//
// Created by ori on 1/13/19.
//

#ifndef PROJ2222_MYCLIENTHANDLER_H
#define PROJ2222_MYCLIENTHANDLER_H


#include "ClientHandler.h"

class MyClientHandler : public ClientHandler {
public:

    void handleClient(string &question, string &answer) override;
};


#endif //PROJ2222_MYCLIENTHANDLER_H
