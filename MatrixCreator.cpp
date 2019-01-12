//
// Created by ori on 1/10/19.
//

#include <iostream>
#include "MatrixCreator.h"
#include "Utils.h"

Matrix* MatrixCreator::createFromConsole() {
    int height=0;
    int width=0;
    string input;
    string line;

    cout << "type your mat (to finish type 'end')" << endl;

    while (true) {
        // get line each time
        getline(cin, line);
        ++height;

        // read until type 'quit'
        if (line == "end") { break; }

        // add '$' after each line
        input += line + "$";
    }

    // fix height
    --height;

    // determine width
    int j=0;
    bool finished=false;
    while(input[j]!='$'&&j<input.size()&&!finished) {
        ++width;
        while (input[j] != ',' && j < input.size()&&!finished) {
            if (input[j] == '$') {
                finished=true;
            }
            ++j;
        }
        ++j;
    }

    Matrix* matrix = new Matrix(height,width);

    int i=0;
    string num;
    while (i<input.size()) {
        vector<int>* row = new vector<int>;
        while (input[i]!='$'&&i<input.size()) {
            num="";
            while (input[i] != ',' && input[i] != '$' && i < input.size()) {
                num+=input[i];
                ++i;
            }
            row->push_back(stoi(num));
            ++i;
        }
        matrix->fill(row);
        ++i;
    }

    Utils utils;
    cout << "type entrance (r:c)" << endl;
    getline(cin, line);
    matrix->setInitialState(utils.getRowCoordintae(line),utils.getColCoordintae(line));

    cout << "type exit (r:c)" << endl;
    getline(cin, line);
    matrix->setGoalState(utils.getRowCoordintae(line),utils.getColCoordintae(line));

    return matrix;
}
