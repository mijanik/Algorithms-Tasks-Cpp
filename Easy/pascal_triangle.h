//
// Created by Milosz on 2025-02-12.
//

#ifndef PASCAL_TRIANGLE_H
#define PASCAL_TRIANGLE_H
#include <vector>

// ROZWIAZANIE REKURSYWNE
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows <= 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1,1}};

        std::vector<std::vector<int>> res = generate(numRows - 1); // poprzednie rzędy
        std::vector<int> new_row(numRows); // nowy rząd
        for (auto i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) new_row[i] = 1; // pierwszy i ostatni element nowego rzędu jest zawsze 1
            else new_row[i] = res[numRows-2][i - 1] + res[numRows-2][i]; // i-ty element rzędu to suma i-1 oraz
        }                                                                // i-tego elementu z poprzedniego rzędu

        res.push_back(new_row); // dodajemy na koniec nowy rząd
        return res;
    }
};

// [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]

#endif //PASCAL_TRIANGLE_H
