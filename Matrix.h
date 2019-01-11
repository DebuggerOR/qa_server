

#ifndef PROJ2222_MATRIX_H
#define PROJ2222_MATRIX_H

#include "vector"
#include "Searchable.h"
#include "State.h"

using namespace std;

class Matrix : public Searchable<int> {
    int numRows;
    int numCols;
    vector<vector<State<int> *> *> *rows;

public:
    Matrix(int rows, int cols);

    void fill(vector<int> *ints);

    void displayMat();

    State<int> *getInitialState();

    State<int> *getGoalState();

    list<State<int>*> *getAllPossibleStates(State<int> *state);
};


#endif //PROJ2222_MATRIX_H
