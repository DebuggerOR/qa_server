

#ifndef PROJ2222_UTILS_H
#define PROJ2222_UTILS_H

#include <string>
#include <vector>
#include <list>
#include <math.h>
#include "Point.h"
#include "State.h"


using namespace std;

class Utils {
public:
    int getRowCoordintae(string crdnt);

    int getColCoordintae(string crdnt);

    string coordinatesToString(vector<string> crdnts);

    string pointsToString(vector<Point *> crdnts);

    Point *stringToPoint(string crdnt);

    double walkDistance(Point *p1, Point *p2);

    double airDistance(Point *p1, Point *p2);

    bool isDig(char c);

    double pathWeight(list<State<Point *> *> *path);
};


#endif
