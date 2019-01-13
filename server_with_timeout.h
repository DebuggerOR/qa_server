//
// Created by ori on 1/13/19.
//

#ifndef PROJ2222_SERVER_WITH_TIMEOUT_H
#define PROJ2222_SERVER_WITH_TIMEOUT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << argv[0] << endl;
    if (argc < 2)	{
        cout << "Usage: <prog> <port>" << endl;
        return 1;
    }
    int port = atoi(argv[1]);
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "Bad!" << endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    new_sock = accept(s, (struct sockaddr*)&client, &clilen);
    if (new_sock < 0)	{
        if (errno == EWOULDBLOCK)	{
            cout << "timeout!" << endl;
            exit(2);
        }	else	{
            perror("other error");
            exit(3);
        }
    }
    cout << new_sock << endl;
    cout << s << endl;
    close(new_sock);
    close(s);
    return 0;
}

#endif //PROJ2222_SERVER_WITH_TIMEOUT_H
