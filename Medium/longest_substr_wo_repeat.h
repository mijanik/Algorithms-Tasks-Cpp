//
// Created by Milosz on 2025-04-11.
//

#ifndef LONGEST_SUBSTR_WO_REPEAT_H
#define LONGEST_SUBSTR_WO_REPEAT_H

#include <string>
#include <unordered_set>

// TODO -  IN PROGRESS
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        auto first = s.begin();
        auto last = first;
        std::unordered_set<char> window;
        int max_size = 0;

        for (auto it : s) {
            if (window.contains(it)) {
                window.erase(it);
                first++;
            }
            window.insert(it);
            last++;
            if (window.size() > max_size) max_size = window.size();
        }
        return max_size;
    }
};

#endif //LONGEST_SUBSTR_WO_REPEAT_H
