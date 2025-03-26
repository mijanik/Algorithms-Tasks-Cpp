//
// Created by Milosz on 2025-01-13.
//

#ifndef PALINDROME_NUMBER_H
#define PALINDROME_NUMBER_H

#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string x_string = std::to_string(x);
        for(int i = 0; i < (x_string.length())/2; i++){
            if(x_string[i] != x_string[x_string.length()-1 - i])
                return false;
        }
        return true;
    }
};

#endif //PALINDROME_NUMBER_H
