

#include "Utils.h"

string Utils::coordinatesToString(vector<string> crdnts) {
    string c1, c2 = crdnts[0];
    string path;
    for (int i = 1; i < crdnts.size(); ++i) {
        c1 = c2;
        c2 = crdnts[i];
        if (this->getRowCoordintae(c1) - 1 == this->getRowCoordintae(c2)) {
            path = "Down," + path;
        }
        if (this->getRowCoordintae(c1) == this->getRowCoordintae(c2) - 1) {
            path = "Up," + path;
        }
        if (this->getColCoordintae(c1) - 1 == this->getColCoordintae(c2)) {
            path = "Right," + path;
        }
        if (this->getColCoordintae(c1) == this->getColCoordintae(c2) - 1) {
            path = "Left," + path;
        }
    }
    path.erase(path.size() - 1);
    return path;
}

int Utils::getRowCoordintae(string crdnt) {
    int i = 0;
    int row = 0;
    while (crdnt[i] != ',') {
        row *= 10;
        row += (crdnt[i] - '0');
        ++i;
    }
    return row;
}

int Utils::getColCoordintae(string crdnt) {
    int i = 0;
    int col = 0;
    while (crdnt[i] != ',') {
        ++i;
    }
    ++i;
    while (i < crdnt.size()) {
        col *= 10;
        col += (crdnt[i] - '0');
        ++i;
    }
    return col;
}

Point *Utils::stringToPoint(string crdnt) {
    return new Point(this->getRowCoordintae(crdnt), this->getColCoordintae(crdnt));
}

string Utils::pointsToString(vector<Point *> crdnts) {
    Point *c1;
    Point *c2 = crdnts[0];
    string path;
    for (int i = 1; i < crdnts.size(); ++i) {
        c1 = c2;
        c2 = crdnts[i];
        if (c1->getRow() - 1 == c2->getRow()) {
            path = "Down," + path;
        }
        if (c1->getRow() == c2->getRow() - 1) {
            path = "Up," + path;
        }
        if (c1->getCol() - 1 == c2->getCol()) {
            path = "Right," + path;
        }
        if (c1->getCol() == c2->getCol() - 1) {
            path = "Left," + path;
        }
    }
    path.erase(path.size() - 1);
    return path;
}

bool Utils::isDig(char c) {
    return (c >= '0' && c <= '9');
}

double Utils::pathWeight(list<State<Point *> *> *path) {
    // case no path
    if (path == NULL) {
        return -1;
    }

    double weight = 0;
    vector<State<Point *> *> vec(begin(*path), end(*path));

    // add all costs instead of the first (last in back trace)
    for (int i = 0; i < vec.size() - 1; ++i) {
        weight += vec[i]->getCost();
    }

    return weight;
}

double Utils::walkDistance(Point *p1, Point *p2) {
    double dy = p1->getRow() - p2->getRow();
    double dx = p1->getCol() - p2->getCol();
    return sqrt(dy * dy + dx * dx);
}

double Utils::airDistance(Point *p1, Point *p2) {
    double dy = abs(p1->getRow() - p2->getRow());
    double dx = abs(p1->getCol() - p2->getCol());
    return dx + dy;
}
