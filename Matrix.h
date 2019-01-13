

#ifndef PROJ2222_MATRIX_H
#define PROJ2222_MATRIX_H

#include "vector"
#include "Searchable.h"
#include "State.h"
#include "Point.h"

using namespace std;

class Matrix : public Searchable<Point*> {
    int numRows;
    int numCols;
    State<Point*> *entrance;
    State<Point*> *exit;
    vector<vector<State<Point*> *> *> *rows;

public:
    Matrix(int rows, int cols);

    void fill(vector<int> *ints);

    void displayMat();

    void setInitialState(int row, int col);

    void setGoalState(int row, int col);

    State<Point*> *getInitialState();

    State<Point*> *getGoalState();

    list<State<Point*> *> *getAllPossibleStates(State<Point*> *state);
};


#endif
