


#ifndef PROJ2222_ASTAR_H
#define PROJ2222_ASTAR_H


#include "Searcher.h"

template <class T>
class AStar : public Searcher<T> {
    list<State<T>*>* search(Searchable<T>* searchable);
};


template<class T>
list<State<T>*>* AStar<T>::search(Searchable<T>* searchable) {
    Utils utils;
    list<State<T>*> visited;
    State<T>* goal = searchable->getGoalState();

    State<T>* state = searchable->getInitialState();
    visited.push_back(state);
    state->setCameFrom(NULL);

    while (true) {
        list<State<T> *> *adj = searchable->getAllPossibleStates(state);
        State<T> *best = NULL;
        for (auto &a : *adj) {
            bool isVisited = false;
            for (auto &v : visited) {
                if(a == v){
                    isVisited = true;
                }
            }

            if(!isVisited) {
                double aDst;
                double bestDst;
                if(best!=NULL) {
                    aDst = a->getCost() + utils.distance(a->getState(), goal->getState());
                    bestDst = best->getCost() + utils.distance(best->getState(), goal->getState());
                }
                if (best==NULL || aDst < bestDst) {
                    best = a;
                    visited.push_back(a);
                    ++this->evaluatedNodes;
                }
            }
        }
        cout<<best->getState()->getRow()<<","<<best->getState()->getCol()<<endl;
        best->setCameFrom(state);
        state=best;
        if(state==goal){
            return this->backTrace(state, searchable);
        }
    }
}






/*
 *
function A_Star(start, goal)
    // The set of nodes already evaluated
    closedSet := {}

    // The set of currently discovered nodes that are not evaluated yet.
    // Initially, only the start node is known.
    openSet := {start}

    // For each node, which node it can most efficiently be reached from.
    // If a node can be reached from many nodes, cameFrom will eventually contain the
    // most efficient previous step.
    cameFrom := an empty map

    // For each node, the cost of getting from the start node to that node.
    gScore := map with default value of Infinity

    // The cost of going from start to start is zero.
    gScore[start] := 0

    // For each node, the total cost of getting from the start node to the goal
    // by passing by that node. That value is partly known, partly heuristic.
    fScore := map with default value of Infinity

    // For the first node, that value is completely heuristic.
    fScore[start] := heuristic_cost_estimate(start, goal)

    while openSet is not empty
        current := the node in openSet having the lowest fScore[] value
        if current = goal
            return reconstruct_path(cameFrom, current)

        openSet.Remove(current)
        closedSet.Add(current)

        for each neighbor of current
            if neighbor in closedSet
                continue		// Ignore the neighbor which is already evaluated.

            // The distance from start to a neighbor
            tentative_gScore := gScore[current] + dist_between(current, neighbor)

            if neighbor not in openSet	// Discover a new node
                openSet.Add(neighbor)
            else if tentative_gScore >= gScore[neighbor]
                continue;

            // This path is the best until now. Record it!
            cameFrom[neighbor] := current
            gScore[neighbor] := tentative_gScore
            fScore[neighbor] := gScore[neighbor] + heuristic_cost_estimate(neighbor, goal)
 *
 *
 *
 *
 * function reconstruct_path(cameFrom, current)
    total_path := {current}
    while current in cameFrom.Keys:
        current := cameFrom[current]
        total_path.append(current)
    return total_path

 *
 *
 */


#endif //PROJ2222_ASTAR_H
