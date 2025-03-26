//
// Created by Milosz on 2025-02-20.
//

#ifndef FIND_STR_IN_STR_H
#define FIND_STR_IN_STR_H
#include <string>
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        return static_cast<int>(haystack.find(needle));
    }
};

#endif //FIND_STR_IN_STR_H
