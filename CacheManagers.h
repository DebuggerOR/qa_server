


#ifndef PROJ2222_CACHEMANAGER_H
#define PROJ2222_CACHEMANAGER_H


#include <map>
#include <fstream>
#include <mutex>

#define CACHE_FILE_NAME "data.txt"

using namespace std;

template<class Problem, class Solution>
class CacheManager {
protected:
    map<Problem, Solution> solutions;

public:
    virtual bool isSavedSolution(Problem problem);

    virtual Solution getSolution(Problem problem);

    virtual void saveSolution(Problem problem, Solution solution);
};

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

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
public:
    FileCacheManager();

    ~FileCacheManager();

    void load();

    void save();
};

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::load() {
    mutex m;
    m.lock();

    string line;
    ifstream file;
    file.open(CACHE_FILE_NAME, ios::in);

    if (file.is_open()) {
        while (getline(file, line)) {
            int i = 0;
            string question, answer;

            // question until @
            while (line[i] != '@') {
                question += line[i];
                ++i;
            }
            ++i;

            // answer until end
            while (i < line.length()) {
                answer += line[i];
                ++i;
            }

            this->solutions.insert(pair<string, string>(question, answer));
        }
        file.close();
    }

    m.unlock();
}

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::save() {
    mutex m;
    m.lock();

    ofstream file(CACHE_FILE_NAME);

    if (file.is_open()) {
        for (auto &qa : this->solutions) {
            file << qa.first << "@" << qa.second << endl;
        }
        file.close();
    } else {
        throw "unable to open file";
    }

    m.unlock();
}

template<class Problem, class Solution>
FileCacheManager<Problem, Solution>::FileCacheManager() {
    this->load();
}

template<class Problem, class Solution>
FileCacheManager<Problem, Solution>::~FileCacheManager() {
    this->save();
}


#endif //PROJ2222_CACHEMANAGER_H
