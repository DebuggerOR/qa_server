//
// Created by ori on 1/13/19.
//

#ifndef PROJ2222_MYCLIENTHANDLER_H
#define PROJ2222_MYCLIENTHANDLER_H


#include <list>
#include "ClientHandler.h"
#include "Solver.h"
#include "Point.h"
#include "State.h"
#include "Searchable.h"

class MyClientHandler : public ClientHandler {
    CacheManager<string,string>* cm;

    Solver<list<State<Point *> *> *, Searchable<Point *> *>* solver;

public:
    MyClientHandler(CacheManager<string, string>* cm, Solver<list<State<Point *> *> *, Searchable<Point *> *>* solver);

    void handleClient(string question, string &answer) override;
};


#endif //PROJ2222_MYCLIENTHANDLER_H
