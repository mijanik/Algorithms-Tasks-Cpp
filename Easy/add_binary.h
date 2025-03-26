//
// Created by Milosz on 2025-01-15.
//

#ifndef ADD_BINARY_H
#define ADD_BINARY_H

#include <algorithm>
#include <string>
#include <cmath>
#include <bitset>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        // Dodawanie cyfr od końca
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // dodanie przeniesienia
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0'; // Dodaj wynik dodawania bitów do wyniku
            carry = sum / 2;           // Oblicz przeniesienie
        }

        // Odwracamy wynik, ponieważ zaczęliśmy od końca
        std::reverse(result.begin(), result.end());
        return result;
    }
};


    // // Konwersja string w systemie BIN na int
    // unsigned long long stringBinarytoULL(std::string s) {
    //     unsigned long long result = 0;
    //     for (int i = 0; i < s.length(); i++) {
    //         result += (s[i] - '0') * pow(2, s.length() - i - 1);
    //     }
    //     return result;
    // }
    // std::string addBinary(std::string a, std::string b) {
    //     unsigned long long result = stringBinarytoULL(a) + stringBinarytoULL(b);
    //
    //     // konwersja z int w systemie DEC na string w systemie BIN, z paddingiem do 8 znaków
    //     std::string result_string = std::bitset<64>(result).to_string();
    //
    //     // usuwanie zer z początku string
    //     result_string = result_string.erase(0, result_string.find_first_not_of('0'));
    //
    //     if (result_string.empty())
    //         result_string = "0";
    //     return result_string;
    // }


#endif //ADD_BINARY_H
