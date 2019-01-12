//
// Created by ori on 1/12/19.
//

#include "Utils.h"

string Utils::coordinatesToString(vector<string> crdnts) {
    string c1, c2 = crdnts[0];
    string path;
    for (int i = 1; i < crdnts.size(); ++i) {
        c1=c2;
        c2=crdnts[i];
        if(this->getRowCoordintae(c1)-1==this->getRowCoordintae(c2)){
            path+="Down,";
        }
        if(this->getRowCoordintae(c1)==this->getRowCoordintae(c2)-1){
            path+="Up,";
        }
        if(this->getColCoordintae(c1)-1==this->getColCoordintae(c2)){
            path+="Right,";
        }
        if(this->getColCoordintae(c1)==this->getColCoordintae(c2)-1){
            path+="Left,";
        }
    }
    path.erase(path.size()-1);
    return path;
}

int Utils::getRowCoordintae(string crdnt) {
    int i=0;
    int row=0;
    while (crdnt[i]!=','){
        row*=10;
        row+=(crdnt[i]-'0');
        ++i;
    }
    return row;
}

int Utils::getColCoordintae(string crdnt) {
    int i=0;
    int col=0;
    while (crdnt[i]!=','){
        ++i;
    }
    ++i;
    while (i<crdnt.size()){
        col*=10;
        col+=(crdnt[i]-'0');
        ++i;
    }
    return col;
}
