//
// Created by Milosz on 2025-01-13.
//

#ifndef ROMAN_TO_INT_H
#define ROMAN_TO_INT_H

#include <string>

class Solution {
public:

    int romanCharToInt(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(std::string s) {
        int number = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                number -= 1;
            }
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                number -= 10;
            }
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                number -= 100;
            }
            else
                number += romanCharToInt(s[i]);
        }
        return number;
    }
};

#endif //ROMAN_TO_INT_H
