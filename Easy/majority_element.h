//
// Created by Milosz on 2025-04-11.
//

#ifndef MAJORITY_ELEMENT_H
#define MAJORITY_ELEMENT_H

#include <vector>
#include <unordered_map>

class Solution {
public:

    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }

        int maxKey = 0;
        int maxValue = 0;

        for (const auto& [key, value] : count) {
            if (value > maxValue) {
                maxValue = value;
                maxKey = key;
            }
        }

        return maxKey;
    }
    // Boyer-Moore Voting Algorithm (bardziej optymalny)
    int majorityElement_BM(vector<int>& nums) {
        int count = 0, candidate = 0;

        for (int num : nums) {
            if (count == 0)
                candidate = num;

            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

#endif //MAJORITY_ELEMENT_H
