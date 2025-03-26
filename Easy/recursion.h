//
// Created by Milosz on 2024-12-06.
//

#ifndef RECURSION_H
#define RECURSION_H

#include <vector>


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if (s.size() < 2) return;

        std::vector<char> v1( s.begin()+1, s.end() -1 );
        reverseString(v1);

        for (int i = 1; i < s.size()-1; i++) {
            s[i] = v1[i-1];
        }

        // std::cout << "DEBUG before swap: ";
        // for (char i : s) {
        //     std::cout << i;
        // }
        //
        // std::cout << "\ns.size: " <<  s.size() << std::endl;;



        char temp = s[0];
        s[0] = s[s.size() - 1];
        s[s.size() - 1] = temp;

    }
};


#endif //RECURSION_H
