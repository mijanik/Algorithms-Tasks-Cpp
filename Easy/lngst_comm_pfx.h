//
// Created by Milosz on 2025-01-13.
//

#ifndef LNGST_COMM_PFX_H
#define LNGST_COMM_PFX_H

#include <string>
#include <vector>



class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int minLen = INT_MAX;
        for (const auto& str : strs)
            if (str.size() < minLen) minLen = static_cast<int>(str.length());

        std::string prefix;

        for (int i = 0; i < minLen; i++) { // i-ty znak stringa
            char c = strs[0][i]; // current char of first string
            for (auto & str : strs) {
                if (str[i] != c) { // sprawdzanie czy i-ty znak bieżącego stringa jest taki sam jak pierwszego
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

#endif //LNGST_COMM_PFX_H
