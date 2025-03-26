//
// Created by Milosz on 2025-01-15.
//

#ifndef LENGTH_LAST_WORD_H
#define LENGTH_LAST_WORD_H

#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ')
                count++;
            else if (s[i] == ' ' && count > 0)
                return count;
        }
        return count;
    }
};

#endif //LENGTH_LAST_WORD_H
