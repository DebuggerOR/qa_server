//
// Created by ori on 1/10/19.
//

#include <iostream>
#include "MatrixCreator.h"

Matrix* MatrixCreator::createFromConsole() {
    int height=0;
    int width=0;
    string input;
    string line;

    cout << "type your mat (to finish type 'exit')" << endl;

    while (true) {
        // get line each time
        getline(cin, line);
        ++height;

        // read until type 'quit'
        if (line == "exit") { break; }

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

    // check width height
    cout<<height<<","<<width<<endl;

    Matrix* matrix = new Matrix(height,width);

    int i=0;
    string num;
    while (i<input.size()) {
        vector<int> row;
        while (input[i]!='$'&&i<input.size()) {
            num="";
            while (input[i] != ',' && input[i] != '$' && i < input.size()) {
                num+=input[i];
                ++i;
            }
            row.push_back(stoi(num));
            ++i;
        }
        matrix->fill(row);
        ++i;
    }

    return matrix;
}
