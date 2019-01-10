//
// Created by ori on 1/10/19.
//

#ifndef PROJ2222_MATRIX_H
#define PROJ2222_MATRIX_H

#include "vector"

using namespace std;

class Matrix {
    int numRows;
    int numCols;
    vector<vector<int>*>* rows;

public:
    Matrix(int rows, int cols);
    void fill(vector<int> ints);
    void displayMat();
};


#endif //PROJ2222_MATRIX_H
