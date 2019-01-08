


#ifndef PROJ2222_BESTFIRSTSEARCH_H
#define PROJ2222_BESTFIRSTSEARCH_H


#include <queue>
#include "Searcher.h"

template <class T, class Solution>
class BestFirstSearch  : public Searcher<T> {

public:
    BestFirstSearch();
    T search(Searchable<T> searchable);
};

template<class T>
Solution BestFirstSearch<T>::search(Searchable<T> searchable) {
    std::priority_queue<State<T>> openList;
    std::list<State<T>> closedList; // TODO find better ds

    openList.push(searchable.getInitialState());
    while(openList.size()>0){
        State<T> n = openList.pop();
        closedList.push_back(n);
        if(n.equals(searchable.getGoalState())){
            // return backTrace() ?? TODO
        }

    }






    return nullptr;
}


#endif //PROJ2222_BESTFIRSTSEARCH_H
