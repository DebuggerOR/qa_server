

#ifndef PROJ2222_POINT_H
#define PROJ2222_POINT_H


class Point {
    int row;
    int col;
public:
    Point(int row, int col);

    void setRow(int row);

    void setCol(int col);

    int getRow();

    int getCol();
};


#endif //PROJ2222_POINT_H
