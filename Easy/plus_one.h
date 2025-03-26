//
// Created by Admin on 23.01.2025.
//

#ifndef PLUS_ONE_H
#define PLUS_ONE_H


#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (digits.back() < 9) // ostatnia cyfra jest mniejsza niż 9
            digits.back()++;
        else {
            //digits.back() = 0;
            for (auto it = digits.rbegin(); it != digits.rend(); it++) {
                if (*it == 9) {
                    *it = 0;
                    if (it == digits.rend()-1) {
                        digits.insert(digits.begin(), 1);
                        break;
                    }
                }
                else {
                    *it = *it + 1;
                    break;
                }
            }
        }

        return digits;
    }
};

#endif //PLUS_ONE_H
