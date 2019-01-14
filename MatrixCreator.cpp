//
// Created by ori on 1/10/19.
//

#include <iostream>
#include <fstream>
#include "MatrixCreator.h"
#include "Utils.h"

Matrix* MatrixCreator::createFromConsole() {
    string input;
    string line;

    cout << "type your mat (to finish type 'end')" << endl;

    while (line != "end") {
        // get line each time
        getline(cin, line);

        // add '$' after each line
        input += line + "$";
    }

    return this->createFromString(input);
}

Matrix *MatrixCreator::createFromString(string input) {
    Utils utils;
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
                if (utils.isDig(input[i])) {
                    num += input[i];
                }
                ++i;
            }
            nums->push_back(stoi(num));
            ++i;
        }
    }
    matrix->fill(nums);

    string rEntrance, cEntrance;
    while(input[i]!= ',') {
        if (utils.isDig(input[i])) {
            rEntrance += input[i];
        }
        ++i;
    }
    ++i;
    while (input[i] != '$') {
        if (utils.isDig(input[i])) {
            cEntrance += input[i];
        }
        ++i;
    }
    ++i;
    
    string rExit, cExit;
    while(input[i]!= ',') {
        if (utils.isDig(input[i])) {
            rExit += input[i];
        }
        ++i;
    }
    ++i;
    while (input[i] != '$') {
        if (utils.isDig(input[i])) {
            cExit += input[i];
        }
        ++i;
    }
    
    matrix->setInitialState(stoi(rEntrance), stoi(cEntrance));
    matrix->setGoalState(stoi(rExit), stoi(cExit));

    return matrix;
}

Matrix *MatrixCreator::createFromFile(string fileName) {
    string line;
    string input;
    ifstream file (fileName);

    if (file.is_open()) {
        getline (file, line);
        input += line + "$";
        while (line != "end") {
            getline (file, line);
            input += line + "$";
        }
        file.close();
    }

    return this->createFromString(input);
}

