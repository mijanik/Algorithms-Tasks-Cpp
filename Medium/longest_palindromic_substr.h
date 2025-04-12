//
// Created by Milosz on 2025-04-12.
//

#ifndef LONGEST_PALINDROMIC_SUBSTR_H
#define LONGEST_PALINDROMIC_SUBSTR_H
#include <string>
using namespace std;

// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab" - Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        // skrajne przypadki
        if (s.size() <= 1) return s;

        // Przypadek, gdy palindrom ma nieparzysta ilość znaków np. "aba" albo "cabac" (>= 3 znaki)
        string longest_substr;

        for (auto it = s.begin()+1; it != s.end()-1; ++it) { // it to środek palindromu
            auto first = it-1;
            auto last = it+1;

            while (*first == *last) { //dopóki lewy równa się prawemu znakowi
                // sprawdzamy rozmiar bieżącego palindromu
                string current_substr(first, last+1);
                if (current_substr.size() > longest_substr.size())
                    longest_substr = current_substr; // jeśli większy to aktualizujemy największy

                //poszerzamy palindrom, jeśli to możliwe
                if (first != s.begin() && last != s.end()-1) {
                    --first;
                    ++last;
                }
                else break; // jeśli nie da się go poszerzyć to przechodzimy dalej w głównej pętli
            }
        }


        // Przypadek, gdy palindrom ma parzysta ilość znaków np. "bb" albo "abba" (>= 2 znaki)
        //                                                                                                 V-
        for (auto it = s.begin(); it != s.end()-1; ++it) { // it to pierwszy z dwóch środkowych znaków np. aa
            auto first = it;
            auto last = it+1;

            while (*first == *last) { //dopóki lewy równa się prawemu znakowi
                // sprawdzamy rozmiar bieżącego palindromu
                string current_substr(first, last+1);
                if (current_substr.size() > longest_substr.size())
                    longest_substr = current_substr; // jeśli większy to aktualizujemy największy

                //poszerzamy palindrom, jeśli to możliwe
                if (first != s.begin() && last != s.end()-1) {
                    --first;
                    ++last;
                }
                else break; // jeśli nie da się go poszerzyć to przechodzimy dalej w głównej pętli
            }
        }

        // jeśli w obu nie znalazł palindromu, to zwróć pierwszy znak
        if (longest_substr.empty()) return s.substr(0, 1);

        return longest_substr; // zwróć najdłuższy palindrom
    }

};

#endif //LONGEST_PALINDROMIC_SUBSTR_H
