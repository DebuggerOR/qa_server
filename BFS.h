


#ifndef PROJ2222_BFS_H
#define PROJ2222_BFS_H


#include <string>
#include "Searcher.h"
#include "list"
#include "map"

#include <iostream>
#include <queue>
#include "Searcher.h"

using std::queue;

template <class T>
class BFS : public Searcher<T, list<State<T>>>{

public:
    list<State<T>> search(Searchable<T> searchable);

private:
    list<State<T>> backTrace(State<T> state, Searchable<T> searchable);
};


/**
 * BFS according Corman
 */

template<class T>
list<State<T>> BFS<T>::search(Searchable<T> searchable) {
    list<State<T>> states = searchable.getAllStates();
    list<State<T>> blacks;
    list<State<T>> grays;
    queue<State<T>> myQueue;
    myQueue.push(searchable.getInitialState());

    while (!myQueue.empty()) {
        State<T> state = myQueue.front();
        list<State<T>> adj = searchable.getAllPossibleStates(state);

        for(auto &a : adj){
            bool isWhite = (find(grays.begin()), grays.end(), a) != grays.end();
            if (isWhite){
                grays.push_back(a);
                a.setCameFrom(state);
                myQueue.push(a);
            }
        }

        myQueue.pop();
        blacks.push_back(state);
    }
}

template<class T>
list<State<T>> BFS<T>::backTrace(State<T> state, Searchable<T> searchable) {
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


#endif //PROJ2
