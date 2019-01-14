//
// Created by ori on 1/10/19.
//

#ifndef PROJ2222_MATRIXHANDLER_H
#define PROJ2222_MATRIXHANDLER_H

#include "string"
#include "Searchable.h"
#include "Matrix.h"

using namespace std;

class MatrixCreator {
public:
    Matrix *createFromString(string input);

    Matrix *createFromConsole();

    Matrix *createFromFile(string fileName);
};

#endif //PROJ2222_MATRIXHANDLER_H
