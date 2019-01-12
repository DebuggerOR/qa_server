//
// Created by ori on 1/12/19.
//

#ifndef PROJ2222_UTILS_H
#define PROJ2222_UTILS_H

#include <string>
#include <vector>

using namespace std;

class Utils {
public:
    int getRowCoordintae(string crdnt);
    int getColCoordintae(string crdnt);
    string coordinatesToString(vector<string> crdnts);
};


#endif //PROJ2222_UTILS_H
