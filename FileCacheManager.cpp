//
// Created by ori on 1/6/19.
//

#include "FileCacheManager.h"

template<class Problem, class Solution>
FileCacheManager<Problem, Solution>::FileCacheManager() {
    string line;
    ifstream file;
    file.open("fly_data.txt", ios::in);

    if (file.is_open()) {
        while (line != "this_is_the_end" && getline(file, line)) {
            int i = 0;
            string question, answer;

            // question until $
            while (line[i] != '$') {
                question += line[i];
                ++i;
            }
            ++i;

            // answer until end
            while (i < line.length()) {
                answer += line[i];
                ++i;
            }
        }
        file.close();
    }
}

template<class Problem, class Solution>
FileCacheManager<Problem, Solution>::~FileCacheManager() {
    ofstream file("qa_data.txt");

    if (file.is_open()) {
        for (auto &qa : this->solutions) {
            file << qa.first << "$" << qa.second << endl;
        }
        file << "this_is_the_end";
        file.close();
    } else {
        throw "unable to open file";
    }
}