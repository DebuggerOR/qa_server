

#ifndef PROJ2222_DFS_H
#define PROJ2222_DFS_H


#include <iostream>
#include "Searcher.h"

template <class T>
class DFS : public Searcher<T>{

public:
    void search(Searchable<T> searchable);

private:
    void visit(State<T> state, list<State<T>> whites, list<State<T>> grays, Searchable<T> searchable);

};


/**
 * DFS according Corman
 */

template<class T>
void DFS<T>::search(Searchable<T> searchable) {
    list<State<T>> states = searchable.getAllStates();
    list<State<T>> blacks;
    list<State<T>> grays;

    this->visit(searchable.getInitialState(), blacks, grays, searchable);
}

template<class T>
void DFS<T>::visit(State<T> state, list<State<T>> blacks, list<State<T>> grays, Searchable<T> searchable) {
    this->evlaluatedNodes=0;

    // if state is goal state
    if(searchable.getGoalState().equals(state)){
        return;
    }

    list<State<T>> adj = searchable.getAllPossibleStates(state);
    grays.push_back(state);

    for(auto &a : adj) {
        bool isWhite = (find(grays.begin()), grays.end(), a) != grays.end();
        if(isWhite) {
            this->evlaluatedNodes++;
            a.setCameFrom(state); // compiler doesnt recognise. weird...
            this->visit(a, blacks, grays, searchable);
        }
    }
    blacks.push_back(state);
}

#endif //PROJ2222_DFS_H
