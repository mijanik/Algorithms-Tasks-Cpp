//
// Created by Milosz on 2025-01-13.
//

#ifndef TWO_SUM_TARGET_H
#define TWO_SUM_TARGET_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i == j) continue;
                //cout << "["<< nums[i] << ", "<< nums[j] << "]" << endl;
                if(nums[i] + nums[j] == target){
                    solution[0] = i;
                    solution[1] = j;
                    return solution;
                }
            }
        }
        return solution;
    }
};

#endif //TWO_SUM_TARGET_H
