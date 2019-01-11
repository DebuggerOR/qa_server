
#include <iostream>
#include "Matrix.h"

void Matrix::fill(vector<int>* allNums) {
    for (int i = 0; i < this->numRows; ++i) {
        for (int j = 0; j < this->numCols; ++j) {
            this->rows->at(i)->at(j)->setCost(allNums->at(i*this->numCols+j));
        }
    }
}

Matrix::Matrix(int rows, int cols) {
    this->numRows=rows;
    this->numCols=cols;
    this->rows = new vector<vector<State<int>*>*>;

    for (int i = 0; i < this->numRows; ++i) {
        vector<State<int>*>* row = new vector<State<int>*>;
        this->rows->push_back(row);
        for (int j = 0; j < this->numCols; ++j) {
            row->push_back(new State<int>);
        }
    }
}

void Matrix::displayMat() {
    cout<<"the mat is:"<<endl;
    for (int i = 0; i < this->numRows; ++i) {
        for (int j = 0; j < this->numCols; ++j) {
            cout<<this->rows->at(i)->at(j)->getCost()<<'\t';
        }
        cout<<endl;
    }
}

State<int>* Matrix::getInitialState() {
    return this->rows->at(0)->at(0);
}

State<int>* Matrix::getGoalState() {
    return this->rows->at(this->numRows-1)->at(this->numCols-1);
}

list<State<int>*>* Matrix::getAllPossibleStates(State<int> *state) {
    int row;
    int col;
    bool isFinished = false;
    for (int i = 0; i < this->numRows && !isFinished; ++i) {
        for (int j = 0; j < this->numCols && !isFinished; ++j) {
            if(this->rows->at(i)->at(j)==state){
                isFinished= true;
                row=i;
                col=j;
            }
        }
    }

    list<State<int>*>* pos = new list<State<int>*>;
    if(row > 0){
        pos->push_back(this->rows->at(row-1)->at(col));
    }

    if (col>0){
        pos->push_back(this->rows->at(row)->at(col-1));
    }

    if(row < this->numRows - 1){
        pos->push_back(this->rows->at(row+1)->at(col));
    }

    if(col < this->numCols -1) {
        pos->push_back(this->rows->at(row)->at(col+1));
    }

    return pos;
}



