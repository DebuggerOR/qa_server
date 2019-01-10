//
// Created by ori on 1/6/19.
//

#include "StringReverser.h"

string StringReverser::solveImp(string problem) {
    string reversed;

    for (int i = problem.length() - 1; i >= 0; --i) {
        reversed += problem[i];
    }

    return reversed;
}