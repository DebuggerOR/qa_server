//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_HILLCLIMBING_H
#define PROJ2222_HILLCLIMBING_H


#include "Searcher.h"

template <class T>
class HillClimbing : public Searcher<T>{
    T search(Searchable<T> searchable);
};

template<class T>
T HillClimbing<T>::search(Searchable<T> searchable) {
    return Searcher<T>::search(searchable);
}


#endif //PROJ2222_HILLCLIMBING_H
