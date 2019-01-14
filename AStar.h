


#ifndef PROJ2222_ASTAR_H
#define PROJ2222_ASTAR_H


#include "Searcher.h"

template <class T>
class AStar : public Searcher<T> {
    list<State<T>*>* search(Searchable<T>* searchable);

private:

    double fromHere(State<T> *state, State<T>* goal);
};


template<class T>
double AStar<T>::fromHere(State<T> *state, State<T>* goal) {
    Utils utils;
    return utils.distance(state, goal);
}

template<class T>
list<State<T>*>* AStar<T>::search(Searchable<T>* searchable) {
    Utils utils;
    list<State<T>*> openList;
    list<State<T>*> closedList;
    map<State<T>*, double> toState;

    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getGoalState();

    openList.push_back(init);
    toState.insert(pair<State<T>*,double>(init,0));

    while(!openList.empty()){
        // find best in open list
        State<T>* best= openList.front();
        for(auto &o : openList){
            if(this->fromHere(o)+toState.at(o)<this->fromHere(best)+toState.at(best)){
                best=o;
            }
        }
        openList.remove(best);

        list<State<T>*>* adj = searchable->getAllPossibleStates(best);
        for(auto &a : adj){
            if(best == a){
                return this->backTrace(a);
            }






            bool isInOpen = false;
            for (auto &o : openList) {
                if(o == a){
                    isInOpen = true;
                    break;
                }
            }

            bool isInClosed = false;
            for (auto &c : closedList) {
                if(c == a){
                    isInClosed = true;
                    break;
                }
            }
            if(isInClosed){
                if(this->fromHere(a)+toState.at(a)<this->fromHere(best)+toState.at(best)){
                    continue;
                }
            }


            if(isInOpen){
                continue;
            }


        }

        closedList.push_back(best);
    }
}







//3.  while the open list is not empty
//        a) find the node with the least f on
//the open list, call it "q"
//
//b) pop q off the open list
//
//c) generate q's 8 successors and set their
//parents to q
//
//        d) for each successor
//i) if successor is the goal, stop search
//        successor.g = q.g + distance between
//        successor and q
//        successor.h = distance from goal to
//successor (This can be done using many
//ways, we will discuss three heuristics-
//Manhattan, Diagonal and Euclidean
//Heuristics)
//
//successor.f = successor.g + successor.h
//
//ii) if a node with the same position as
//        successor is in the OPEN list which has a
//lower f than successor, skip this successor
//
//        iii) if a node with the same position as
//        successor  is in the CLOSED list which has
//        a lower f than successor, skip this successor
//        otherwise, add  the node to the open list
//end (for loop)
//
//e) push q on the closed list
//end (while loop)


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
