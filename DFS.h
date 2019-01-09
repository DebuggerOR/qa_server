//
// Created by ori on 1/6/19.
//

#ifndef PROJ2222_DFS_H
#define PROJ2222_DFS_H


#include <iostream>
#include "Searcher.h"

template <class T>
class DFS : public Searcher<T, list<State<T>>>{

public:
    list<State<T>> search(Searchable<T> searchable);

private:
    list<State<T>> backTrace(State<T> state, Searchable<T> searchable);
    void visit(State<T> state, list<State<T>> whites, list<State<T>> grays, Searchable<T> searchable);

};


/**
 * DFS according Corman
 */

template<class T>
list<State<T>> DFS<T>::search(Searchable<T> searchable) {
    list<State<T>> states = searchable.getAllStates();
    list<State<T>> blacks;
    list<State<T>> grays;

    for(auto &s : states) {
        bool isWhite = (find(grays.begin()), grays.end(), s) != grays.end();
        if(isWhite){
            this->visit(s, blacks, grays, searchable);
        }
    }
}

template<class T>
void DFS<T>::visit(State<T> state, list<State<T>> blacks, list<State<T>> grays, Searchable<T> searchable) {
    list<State<T>> adj = searchable.getAllPossibleStates(state);
    grays.push_back(state);

    for(auto &a : adj) {
        bool isWhite = (find(grays.begin()), grays.end(), a) != grays.end();
        if(isWhite) {
            a.setCameFrom(state); // compiler doesnt recognise. weird...
            this->visit(a, blacks, grays, searchable);
        }
    }
    blacks.push_back(state);
}

template<class T>
list<State<T>> DFS<T>::backTrace(State<T> state, Searchable<T> searchable) {
    list<State<T>> trace;

    if (state.equals(searchable.getInitialState())) {
        trace.push_back(state);
    } else if (state.getCameFrom() == nullptr) {
        std::cout << "no path" << endl;
    } else {
        backTrace(state.getCameFrom(), searchable);
        trace.push_back(state);
    }

    return trace;
}


#endif //PROJ2222_DFS_H
