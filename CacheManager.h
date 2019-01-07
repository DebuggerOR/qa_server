


#ifndef PROJ2222_CACHEMANAGER_H
#define PROJ2222_CACHEMANAGER_H


#include <map>

using namespace std;

template <class Problem ,class Solution>
class CacheManager {
protected:
    map<Problem, Solution> solutions;

public:
    virtual bool isSavedSolution(Problem problem);

    virtual Solution getSolution(Problem problem);

    virtual void saveSolution(Problem problem, Solution solution);
};


#endif //PROJ2222_CACHEMANAGER_H
