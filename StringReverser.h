//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_STRINGREVERSER_H
#define PROJ2222_STRINGREVERSER_H


#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {

public:
    string solve(string problem) override;
};



#endif //PROJ2222_STRINGREVERSER_H
