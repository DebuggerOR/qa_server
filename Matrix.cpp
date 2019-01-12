
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
    this->rows = new vector<vector<State<string>*>*>;

    for (int i = 0; i < this->numRows; ++i) {
        vector<State<string>*>* row = new vector<State<string>*>;
        this->rows->push_back(row);
        for (int j = 0; j < this->numCols; ++j) {
            row->push_back(new State<string>(to_string(i)+","+to_string(j)));
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

State<string>* Matrix::getInitialState() {
    return this->entrance;
}

State<string>* Matrix::getGoalState() {
    return this->exit;
}

list<State<string>*>* Matrix::getAllPossibleStates(State<string> *state) {
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

    auto * pos = new list<State<string>*>;
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

void Matrix::setInitialState(int row, int col) {
    this->entrance=this->rows->at(row)->at(col);
}

void Matrix::setGoalState(int row, int col) {
    this->exit=this->rows->at(row)->at(col);
}



