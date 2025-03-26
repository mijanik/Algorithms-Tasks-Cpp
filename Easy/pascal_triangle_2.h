//
// Created by Milosz on 2025-02-12.
//

#ifndef PASCAL_TRIANGLE_2_H
#define PASCAL_TRIANGLE_2_H
#include <vector>

class Solution {
public:
    // // funkcja licząca silnię
    // long long factorial(int n) {
    //     long long res = 1;
    //     for (int i = 2; i <= n; i++)
    //         res *= i;
    //     return res;
    // }

    // std::vector<int> getRow(int rowIndex) {
    //     if (rowIndex < 0) return {};
    //     if (rowIndex == 0) return {1};
    //     if (rowIndex == 1) return {1, 1};
    //     if (rowIndex == 2) return {1, 2, 1};
    //
    //     // Liczymy od 0, 0-wy wiersz ma 1 element, 1. ma 2 elementy ...
    //     std::vector<int> res(rowIndex+1);
    //     res[0] = 1;
    //
    //     // Gotowy wzór
    //     for (int i = 1; i < rowIndex+1; i++)
    //         res[i] = factorial(rowIndex) / (factorial(i) * factorial(rowIndex-i));
    //
    //     return res;
    // }

    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(rowIndex + 1, 1); // Inicjalizujemy wszystkie wartości na 1

        // Szybsze liczenie iteracyjne
        for (int i = 1; i < rowIndex; i++) {
            res[i] = (long long) res[i - 1] * (rowIndex - i + 1) / i;
        }

        return res;
    }

};

#endif //PASCAL_TRIANGLE_2_H
