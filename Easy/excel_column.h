//
// Created by Milosz on 2025-03-12.
//

#ifndef EXCEL_COLUMN_H
#define EXCEL_COLUMN_H
#include <string>

class Solution {
public:
    // 0 -> A
    // 1 -> B
    // ...
    static char numberToChar(const int num) {
        return static_cast<char>(num + 'A');
    }
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber > 0) {
            columnNumber--; // indeksowanie w excelu jest od 1
            int current_letter = columnNumber % 26; // podstawa systemu to 26
            result.insert(0, 1, numberToChar(current_letter));
            columnNumber /= 26;
        }
        return result;
    }
};

#endif //EXCEL_COLUMN_H
