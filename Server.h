


#ifndef PROJ2222_SERVER_H
#define PROJ2222_SERVER_H


#include "ClientHandler.h"

//namespace server_side {
    class Server {

    public:
        virtual void start(int port, ClientHandler* c);

        virtual void stop();
    };
//}


#endif //PROJ2222_SERVER_H
