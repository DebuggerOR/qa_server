


#ifndef PROJ2222_BESTFIRSTSEARCH_H
#define PROJ2222_BESTFIRSTSEARCH_H


#include <queue>
#include <algorithm>
#include "Searcher.h"


using std::list;
using std::priority_queue;
using std::find;

template <class T>
class BestFirstSearch  : public Searcher<T> {

public:
    list<State<T>> search(Searchable<T> searchable);

private:
    list<State<T>> backTrace(State<T>);
};

template<class T>
list<State<T>> BestFirstSearch<T>::search(Searchable<T> searchable) {
    priority_queue<State<T>> openList;
    list<State<T>> closedList; // TODO find better ds

    openList.push(searchable.getInitialState());
    while(openList.size()>0){
        State<T> n = openList.pop();
        closedList.push_back(n);
        if(n.equals(searchable.getGoalState())){
            return backTrace(n);
        }
        list<State<T>> successors = searchable.getAllPossibleStates(n);
        for (auto &s : successors) {
            bool isClosedContains = (find(closedList.begin(), closedList.end(), s) != closedList.end());
            bool isOpenContains = (find(openList.begin()), openList.end(), s) != openList.end();

            // if s is not is CLOSED and s is not in OPEN
            if(!isClosedContains && !isOpenContains){
                s.setCameFrom(n);
                openList.push(s);

                // otherwise, if this new path is better than prev one
            } else if(true) {

                // if it is not in OPEN add it to OPEN
                if (!isOpenContains(s)) {
                    openList.push(s);

                    // otherwise adjust its priority in OPEN
                } else {

                }
            }
        }
    }

    return nullptr;
}

template<class T>
list<State<T>> BestFirstSearch<T>::backTrace(State<T>) {
    list<State<T>> trace;
    State<T> s;

    while (s != nullptr) {
        trace.push_back(s.getCameFrom());
        s = s.getCameFrom();
    }

    return trace;
}



#endif
