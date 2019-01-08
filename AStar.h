


#ifndef PROJ2222_ASTAR_H
#define PROJ2222_ASTAR_H


#include "Searcher.h"

template <class T>
class AStar : public Searcher<T> {
    T search(Searchable<T> searchable);

};

template<class T>
T AStar<T>::search(Searchable<T> searchable) {
    return Searcher<T>::search(searchable);
}


#endif //PROJ2222_ASTAR_H
