


#ifndef PROJ2222_CACHEMANAGER_H
#define PROJ2222_CACHEMANAGER_H


#include <map>
#include <fstream>
#define CACHE_FILE_NAME "data.txt"

using namespace std;

template <class Problem ,class Solution>
class CacheManagers {
protected:
    map<Problem, Solution> solutions;

public:
    virtual bool isSavedSolution(Problem problem);

    virtual Solution getSolution(Problem problem);

    virtual void saveSolution(Problem problem, Solution solution);
};

template<class Problem, class Solution>
bool CacheManagers<Problem, Solution>::isSavedSolution(Problem problem) {
    cout<<"isSavedSolution"<<endl;
    return solutions.count(problem) != 0;
}

template<class Problem, class Solution>
Solution CacheManagers<Problem, Solution>::getSolution(Problem problem) {
    cout<<"getSolution"<<endl;
    return solutions[problem];
}

template<class Problem, class Solution>
void CacheManagers<Problem, Solution>::saveSolution(Problem problem, Solution solution) {
    cout<<"saveSolution"<<endl;
    solutions[problem] = solution;
}

template <class Problem ,class Solution>
class FileCacheManager: public CacheManagers<Problem,Solution> {
public:
    FileCacheManager();

    ~FileCacheManager();

    void load();

    void save();
};

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::load() {
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

            this->solutions.insert(pair<string,string>(question,answer));
        }
        file.close();
    }
}

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::save() {
    ofstream file(CACHE_FILE_NAME);

    if (file.is_open()) {
        for (auto &qa : this->solutions) {
            file << qa.first << "@" << qa.second << endl;
        }
        file.close();
    } else {
        throw "unable to open file";
    }
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
