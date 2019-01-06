//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_FILECACHEMANAGER_H
#define PROJ2222_FILECACHEMANAGER_H


#include <fstream>
#include "CacheManager.h"


template <class Problem ,class Solution>
class FileCacheManager: public CacheManager<Problem, Solution> {

public:
    FileCacheManager();

    ~FileCacheManager();
};


#endif //PROJ2222_FILECACHEMANAGER_H
