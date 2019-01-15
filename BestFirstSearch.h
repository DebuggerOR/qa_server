


#ifndef PROJ2222_BESTFIRSTSEARCH_H
#define PROJ2222_BESTFIRSTSEARCH_H


#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Searcher.h"

using namespace std;

template <class T>
class BestFirstSearch  : public Searcher<T> {
public:
    list<State<T>*>* search(Searchable<T>* searchable);
};


template<class T>
list<State<T> *> *BestFirstSearch<T>::search(Searchable<T> *searchable) {
    this->evaluatedNodes=0;

    // list of nodes that need to be checked
    list<State<T>*> openList;
    //list of nodes that have been checked
    list<State<T>*> closedList;
    map<State<T>*, double> toState;

    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getGoalState();

    openList.push_back(init);
    toState[init]=0;

    while(!openList.empty()){
        State<T>* best= openList.front();
        for(auto &o : openList){
            if(toState.at(o)<toState.at(best)){
                best=o;
            }
        }
        openList.remove(best);
        closedList.push_back(best);
        ++this->evaluatedNodes;


        list<State<T>*>* adj = searchable->getAllPossibleStates(best);
        for(auto &a : *adj) {
            if (a == goal) {
                a->setCameFrom(best);
                return this->backTrace(a, searchable);
            }

            // if in the closed list ignore
            bool isInClosed = false;
            for (auto &c : closedList) {
                if (c == a) {
                    isInClosed = true;
                    break;
                }
            }
            if (isInClosed) {
                continue;
            }

            // if already in open list, check if the total score
            // when we use the current generated path to get there
            // if it is, update its score and parent
            bool isInOpen = false;
            for (auto &o : openList) {
                if (o == a) {
                    isInOpen = true;
                    break;
                }
            }
            if (isInOpen) {
                if (toState[best] + a->getCost() < toState[a]) {
                    a->setCameFrom(best);
                    toState[a]=toState[best]+a->getCost();
                    best = a;
                }
                // if not in the open list add it and compute its score
            } else {
                a->setCameFrom(best);
                toState[a]=toState[best]+a->getCost();
                openList.push_back(a);
            }
        }
        closedList.push_back(best);
    }
}




#endif

