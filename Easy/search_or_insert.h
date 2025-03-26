//
// Created by Milosz on 2025-01-13.
//

#ifndef SEARCH_OR_INSERT_H
#define SEARCH_OR_INSERT_H

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
            if  (nums[i] > target) {
                return i;
            }
        }
        return nums.size();
    }
};

#endif //SEARCH_OR_INSERT_H
