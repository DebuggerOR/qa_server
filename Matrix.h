

#ifndef PROJ2222_MATRIX_H
#define PROJ2222_MATRIX_H

#include "vector"
#include "Searchable.h"
#include "State.h"

using namespace std;

class Matrix : public Searchable<string> {
    int numRows;
    int numCols;
    State<string> * entrance;
    State<string> * exit;
    vector<vector<State<string> *> *> *rows;

public:
    Matrix(int rows, int cols);

    void fill(vector<int> *ints);

    void displayMat();

    void setInitialState(int row, int col);

    void setGoalState(int row, int col);

    State<string> *getInitialState();

    State<string> *getGoalState();

    list<State<string>*> *getAllPossibleStates(State<string> *state);
};


#endif //PROJ2222_MATRIX_H
