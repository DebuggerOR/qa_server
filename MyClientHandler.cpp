//
// Created by ori on 1/13/19.
//

#include "MyClientHandler.h"
#include "MatrixCreator.h"


void MyClientHandler::handleClient(string question, string answer) {
    cout<<question<<endl;
    MatrixCreator matrixCreator;
    Matrix* matrix = matrixCreator.createFromString(question);

}
