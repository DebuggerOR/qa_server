


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


//template <class T, class S, class C>
//S& Container(priority_queue<T, S, C>& q) {
//    struct HackedQueue : private priority_queue<T, S, C> {
//        static S& Container(priority_queue<T, S, C>& q) {
//            return q.*&HackedQueue::c;
//        }
//    };
//    return HackedQueue::Container(q);
//}

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:

    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};

template<class T>
list<State<T> *> *BestFirstSearch<T>::search(Searchable<T> *searchable) {
    // if initial case is goal state
    if (searchable->getInitialState() == searchable->getGoalState()) {
        return this->backTrace(searchable->getInitialState(), searchable);
    }

    list<State<T> *> blacks;
    list<State<T> *> grays;
    custom_priority_queue<State<T> *> myQueue;
    myQueue.push(searchable->getInitialState());

    while (!myQueue.empty()) {
        State<T> *state = myQueue.top();
        myQueue.pop();
        ++this->evaluatedNodes;

        // if state is goal state
        if (searchable->getGoalState() == state) {
            return this->backTrace(state, searchable);
        }

        list<State<T> *> adj = *(searchable->getAllPossibleStates(state));

        for (auto &a : adj) {
            bool isWhite = true;
            for (auto &g : grays) {
                if (a == g) {
                    isWhite = false;
                }
            }

            if (isWhite) {
                grays.push_back(a);
                a->setCameFrom(state);
                myQueue.push(a);
            }
        }

        blacks.push_back(state);
    }
}







//    priority_queue<State<T> *> open;
//
//    open.push(searchable->getInitialState());
//    list<State<T> *> closed;
//    while (!open.empty()) {
//        State<T> *s = open.top();
//        open.pop();
//        closed.push_back(s);
//
//        if (s == (searchable->getGoalState())) {
//            cout<<"best first search back trace"<<endl;
//            return this->backTrace(s, searchable);
//        } else {
//            list<State<T> *> *adj = searchable->getAllPossibleStates(s);
//            for (auto &a : *adj) {
//                bool isInOpen = false;
//                bool isInClosed = false;
//                vector<State<T>*> &vec = Container(open);
//                for (auto &v : vec) {
//                    if (v == a) {
//                        isInOpen = true;
//                    }
//                }
//                for (auto &v : closed) {
//                    if (v == a) {
//                        isInClosed = true;
//                    }
//                }
//
//
//                if (!isInClosed && !isInOpen) {
//                    a->setCameFrom(s);
//                    open.push(a);
//                } else {
//                    if (a->getCost() > (s->getCost() + 1)) {
//                        a->setCost(s->getCost() + 1);
//                        a->setCameFrom(s);
//                    }
//                    if (!isInOpen) {
//                        open.push(a);
//                    }
//                    //todo Otherwise, adjust its priority in OPEN??
//                }
//
//
////                if (!isInOpen && !isInClosed) {
////                    a->setCameFrom(s);
////                    open.push(s);
////                    } else {
////                    // this path is better than prev
////                    if (a->getCost() > s->getCost() + 1) {
////                        if (!isInOpen) {
////                            open.push(a);
////                        } else {
////                            a->setCost(s->getCost() + 1);
////                        }
////                    }
////                }



#endif

