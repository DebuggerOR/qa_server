//
// Created by ori on 1/6/19.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string reversed;

    for (int i = static_cast<int>(problem.length() - 1); i >= 0; --i) {
        reversed += problem[i];
    }

    return reversed;
}