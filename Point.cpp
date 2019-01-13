//
// Created by ori on 1/13/19.
//

#include "Point.h"

Point::Point(int row, int col) {
    this->row=row;
    this->col=col;
}

void Point::setRow(int row) {
    this->row=row;
}

void Point::setCol(int col) {
    this->col=col;
}

int Point::getRow() {
    return this->row;
}

int Point::getCol() {
    return this->col;
}






