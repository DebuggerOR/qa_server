//
// Created by ori on 1/10/19.
//

#include <iostream>
#include "Matrix.h"

void Matrix::fill(vector<int> allNums) {
    for (int i = 0; i < this->numRows; ++i) {
        auto * row = new vector<int>;
        this->rows->push_back(row);
        for (int j = 0; j < this->numCols; ++j) {
            row->push_back(allNums[i*this->numCols+j]);
        }
    }
}

Matrix::Matrix(int rows, int cols) {
    this->numRows=rows;
    this->numCols=cols;
    this->rows = new vector<vector<int>*>;
}

void Matrix::displayMat() {
    cout<<"the mat is:"<<endl;
    for (int i = 0; i < this->numRows; ++i) {
        for (int j = 0; j < this->numCols; ++j) {
            cout<<this->rows->at(i)->at(j)<<'\t';
        }
        cout<<endl;
    }
}


