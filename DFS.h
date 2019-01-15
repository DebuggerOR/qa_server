

#ifndef PROJ2222_DFS_H
#define PROJ2222_DFS_H


#include <iostream>
#include <map>
#include <stack>
#include "Searcher.h"

using std::stack;

template <class T>
class DFS : public Searcher<T> {
public:
    list<State<T>*>* search(Searchable<T>* searchable);
};

template<class T>
list<State<T>*>* DFS<T>::search(Searchable<T>* searchable) {
    this->evaluatedNodes=0;

    // if initial case is goal state
    if(searchable->getInitialState() == searchable->getGoalState()){
        return this->backTrace(searchable->getInitialState(), searchable);
    }

    stack<State<T>*> myStack;
    myStack.push(searchable->getInitialState());
    map<State<T>*,char>* colors = new map<State<T>*,char>;

    while (!myStack.empty()) {
        State<T>* state = myStack.top();
        myStack.pop();
        ++this->evaluatedNodes;

        // if state is goal state
        if(searchable->getGoalState() == state){
            return this->backTrace(state, searchable);
        }

        list<State<T>*>* adj = searchable->getAllPossibleStates(state);

        for(auto &a : *adj){
            if(!colors->count(a)) {
                colors->insert(pair<State<T>*,char>(a,'g'));
                a->setCameFrom(state);
                myStack.push(a);
            }
        }

        colors->insert(pair<State<T>*,char>(state,'b'));
    }
}


#endif //PROJ2222_DFS_H
