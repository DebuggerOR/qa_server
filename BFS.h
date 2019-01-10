


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
class BFS : public Searcher<T> {

public:
    void search(Searchable<T> searchable);
};



/**
 * BFS according Corman
 */

template<class T>
void BFS<T>::search(Searchable<T> searchable) {
    this->evlaluatedNodes=0;


    // if initial case is goal state
    if(searchable.getInitialState().equals(searchable.getGoalState())){
        return;
    }

    list<State<T>> states = searchable.getAllStates();
    list<State<T>> blacks;
    list<State<T>> grays;
    queue<State<T>> myQueue;
    myQueue.push(searchable.getInitialState());

    while (!myQueue.empty()) {
        State<T> state = myQueue.front();
        this->evlaluatedNodes++;

        // if state is goal state
        if(searchable.getGoalState().equals(state)){
            return this->backTrace(state);
        }

        list<State<T>> adj = searchable.getAllPossibleStates(state);

        for(auto &a : adj){
            bool isWhite = (find(grays.begin()), grays.end(), a) != grays.end();
            if (isWhite){
                grays.push_back(a);
                a.setCameFrom(state); // TODO doesnt recognise func
                myQueue.push(a);
            }
        }

        myQueue.pop();
        blacks.push_back(state);
    }
}


#endif //PROJ2
