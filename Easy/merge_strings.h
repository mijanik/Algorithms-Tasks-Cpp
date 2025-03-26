//
// Created by Milosz on 2025-01-02.
//

#ifndef MERGE_STRINGS_H
#define MERGE_STRINGS_H

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 1;
        for (char c : word2) {
            if (i > word1.size()) {
                word1.push_back(c);
                continue;
            }
            word1.insert(word1.begin()+i, c);
            i+=2;

        }
        return word1;
    }
};

#endif //MERGE_STRINGS_H
