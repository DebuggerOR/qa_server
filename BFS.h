


#ifndef PROJ2222_BFS_H
#define PROJ2222_BFS_H


#include <string>
#include "Searcher.h"

template <class T>
class BFS : public Searcher<T>{
    T search(Searchable<T> searchable);
};

template<class T>
T BFS<T>::search(Searchable<T> searchable) {
    return nullptr;
}

#endif //PROJ2222_BFS_H
