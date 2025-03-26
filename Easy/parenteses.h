//
// Created by Milosz on 2025-01-13.
//

#ifndef PARENTESES_H
#define PARENTESES_H

#include <map>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::map<char, char> matching;
        matching[')'] = '(';
        matching[']'] = '[';
        matching['}'] = '{';

        for ( char c : s ) {
            if ( c == '(' || c == '{' || c == '[' ) {
                stack.push( c );
            }
            else if ( c == ')' || c == '}' || c == ']' ) {
                if (!stack.empty() && stack.top() == matching[c]) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};


#endif //PARENTESES_H
