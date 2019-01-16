


#ifndef PROJ2222_BFS_H
#define PROJ2222_BFS_H


#include <string>
#include <list>
#include <map>
#include <iostream>
#include <queue>

#include "Searcher.h"

using std::queue;

template<class T>
class BFS : public Searcher<T> {
public:
    list<State<T> *> *search(Searchable<T> *searchable);
};

template<class T>
list<State<T> *> *BFS<T>::search(Searchable<T> *searchable) {
    this->evaluatedNodes = 0;

    // if initial case is goal state
    if (searchable->getInitialState() == searchable->getGoalState()) {
        return this->backTrace(searchable->getInitialState(), searchable);
    }

    list<State<T> *> blacks;
    list<State<T> *> grays;
    queue<State<T> *> myQueue;
    myQueue.push(searchable->getInitialState());
    map<State<T> *, char> *colors = new map<State<T> *, char>;

    while (!myQueue.empty()) {
        State<T> *state = myQueue.front();
        myQueue.pop();
        ++this->evaluatedNodes;

        // if state is goal state
        if (searchable->getGoalState() == state) {
            delete colors;
            return this->backTrace(state, searchable);
        }

        list<State<T> *> *adj = searchable->getAllPossibleStates(state);

        for (auto &a : *adj) {
            if (!colors->count(a)) {
                colors->insert(pair<State<T> *, char>(a, 'g'));
                a->setCameFrom(state);
                myQueue.push(a);
            }
        }
        delete adj;

        colors->insert(pair<State<T> *, char>(state, 'b'));
    }

    delete colors;

    return nullptr;
}


#endif //PROJ2
