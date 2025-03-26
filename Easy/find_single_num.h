//
// Created by Milosz on 2025-02-12.
//

#ifndef FIND_SINGLE_NUM_H
#define FIND_SINGLE_NUM_H

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; // zaczynamy od 0
        for (auto i : nums)
            result ^= i; // XOR każdym elementem
        return result;
    }
};

// dla tablicy [4, 1, 2, 1, 2]
// 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4

#endif //FIND_SINGLE_NUM_H
