


#ifndef PROJ2222_BFS_H
#define PROJ2222_BFS_H


#include <string>
#include <list>
#include <map>
#include <iostream>
#include <queue>

#include "Searcher.h"

using std::queue;

template <class T>
class BFS : public Searcher<T> {
public:
    list<State<T>*>* search(Searchable<T>* searchable);
};

/**
 * BFS according Corman
 */

template<class T>
list<State<T>*>* BFS<T>::search(Searchable<T>* searchable) {
    // if initial case is goal state
    if(searchable->getInitialState() == searchable->getGoalState()){
        return this->backTrace(searchable->getInitialState(), searchable);
    }

    list<State<T>*> blacks;
    list<State<T>*> grays;
    queue<State<T>*> myQueue;
    myQueue.push(searchable->getInitialState());

    while (!myQueue.empty()) {
        State<T>* state = myQueue.front();
        ++this->evaluatedNodes;

        // if state is goal state
        if(searchable->getGoalState() == state){
            return this->backTrace(state, searchable);
        }

        list<State<T>*> adj = *(searchable->getAllPossibleStates(state));

        for(auto &a : adj){
            bool isWhite = true;
            for (auto &g : grays) {
                if(a == g){
                    isWhite= false;
                }
            }

            if (isWhite){
                grays.push_back(a);
                a->setCameFrom(state);
                myQueue.push(a);
            }
        }

        myQueue.pop();
        blacks.push_back(state);
    }
}



#endif //PROJ2
