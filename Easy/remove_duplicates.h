//
// Created by Milosz on 2025-01-20.
//

#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <vector>

class Solution {
public:
    int removeDuplicates(std:: vector<int>& nums) {
        int unique = 1; // number of numbers in vector
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // if current number is different from previous
                nums[unique] = nums[i]; // move the unique number to position after last unique
                unique++;
            }
        }
        return unique;
    }
};

#endif //REMOVE_DUPLICATES_H
