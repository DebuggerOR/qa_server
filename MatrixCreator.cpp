//
// Created by ori on 1/10/19.
//

#include <iostream>
#include "MatrixCreator.h"
#include "Utils.h"

Matrix* MatrixCreator::createFromConsole() {
    string input;
    string line;

    cout << "type your mat (to finish type 'end')" << endl;

    while (true) {
        // get line each time
        getline(cin, line);

        // read until type 'quit'
        if (line == "end") { break; }

        // add '$' after each line
        input += line + "$";
    }

    return this->createFromString(input);
}

Matrix *MatrixCreator::createFromString(string input) {
    int height = 0;
    int width = 0;

    // determine height
    for(int i=1; i<input.size();++i){
        if(input[i]=='$'){
            ++height;
        }
    }
    height -= 3;

    // determine width
    int j = 0;
    bool finished = false;
    while (input[j] != '$' && !finished) {
        ++width;
        while (input[j] != ',' && !finished) {
            if (input[j] == '$') {
                finished = true;
            }
            ++j;
        }
        ++j;
    }

    Matrix *matrix = new Matrix(height, width);

    int i = 0;
    string num;
    vector<int> *nums = new vector<int>;
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            num = "";
            while (input[i] != ',' && input[i] != '$') {
                num += input[i];
                ++i;
            }
            nums->push_back(stoi(num));
            ++i;
        }
    }
    matrix->fill(nums);

    string entrance;
    while (input[i] != '$') {
        entrance += input[i];
        ++i;
    }
    ++i;
    string exit;
    while (i < input.size() && input[i] != '$') {
        exit += input[i];
        ++i;
    }

    Utils utils;
    matrix->setInitialState(utils.getRowCoordintae(entrance), utils.getColCoordintae(entrance));
    matrix->setGoalState(utils.getRowCoordintae(exit), utils.getColCoordintae(exit));

    return matrix;
}
