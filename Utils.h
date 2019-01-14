

#ifndef PROJ2222_UTILS_H
#define PROJ2222_UTILS_H

#include <string>
#include <vector>
#include <math.h>
#include "Point.h"


using namespace std;

class Utils {
public:
    int getRowCoordintae(string crdnt);

    int getColCoordintae(string crdnt);

    string coordinatesToString(vector<string> crdnts);

    string pointsToString(vector<Point*> crdnts);

    Point* stringToPoint(string crdnt);

    double distance(Point* p1, Point* p2);

    bool isDig(char c);
};


#endif
