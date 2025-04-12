//
// Created by Milosz on 2025-04-11.
//

#ifndef LONGEST_SUBSTR_WO_REPEAT_H
#define LONGEST_SUBSTR_WO_REPEAT_H

#include <string>
#include <unordered_set>

class Solution {
public:

    //  abcdbab
    //  |__| -> poszerzamy okno w prawo i jak napotkamy duplikat, to zmniejszamy od lewej,
    //  aż nie pozbędziemy się duplikatu

    int lengthOfLongestSubstring(std::string s) {
        auto first = s.begin(); // pierwszy element przesuwanego okna
        std::unordered_set<char> window; //zbiór elementów w badanym oknie
        int max_size = 0; // maksymalny rozmiar z badanych okien -> wynik

        for (char current : s) {
            if (window.contains(current)) { // jeśli napotkamy powtórzenie                abcdbab
                while (*first != current) { // usuwamy wszystkie elementy przed powtórką  *___|
                    window.erase(*first);
                    ++first;
                }
                window.erase(*first); // usuwamy pierwsze wystąpienie powtórzenia   abcdbab
                ++first; //                                                          *__|
            }                                                // abcdbab
            window.insert(current); //poszerzamy okno w prawo     |_|
            if (window.size() > max_size) max_size = window.size(); // sprawdzamy, czy bieżące okno jest największe
        }
        return max_size;
    }
};

#endif //LONGEST_SUBSTR_WO_REPEAT_H
