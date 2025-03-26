#ifndef VALID_PALINDROME_H
#define VALID_PALINDROME_H

#include <string>

class Solution {
public:
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') // A = 65, Z = 90, a = 97, z = 122
            return c + ('a' - 'A');
        return c;
    }
    bool isPalindrome(std::string s) {
        std::erase_if(s, [](const char c) { return c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122; });
        // usuwanie znaków nie-alfanumerycznych
        // 0-9 -> ASCII 48-75
        // A-Z -> ASCII 65-90
        // a-z -> ASCII 97-122

        //std::string copy(s); // Konstruktor kopiujący
        //std::reverse(s.begin(), s.end()); // obracanie skopiowanego stringa

        // porównywanie string idąc od początku i od końca (wystarczy iterować do połowy)
        for (int i = 0; i < s.size() / 2; i++) {
            if (toLower(s[i]) != toLower(s[s.size() - 1 - i])) {
                return false;
            }
        }
        return true;
    }
};

#endif //VALID_PALINDROME_H
