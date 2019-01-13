

#ifndef PROJ2222_UTILS_H
#define PROJ2222_UTILS_H

#include <string>
#include <vector>
#include "Point.h"


using namespace std;

class Utils {
public:
    int getRowCoordintae(string crdnt);

    int getColCoordintae(string crdnt);

    string coordinatesToString(vector<string> crdnts);

    Point* stringToPoint(string crdnt);
};


#endif
