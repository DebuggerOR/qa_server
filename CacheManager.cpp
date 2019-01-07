


#include "CacheManager.h"

template<class Problem, class Solution>
bool CacheManager<Problem, Solution>::isSavedSolution(Problem problem) {
    return solutions.count(problem) != 0;
}

template<class Problem, class Solution>
Solution CacheManager<Problem, Solution>::getSolution(Problem problem) {
    return solutions[problem];
}

template<class Problem, class Solution>
void CacheManager<Problem, Solution>::saveSolution(Problem problem, Solution solution) {
    solutions[problem] = solution;
}