//
// Created by Milosz on 2025-01-02.
//

#ifndef NWD_STRING_H
#define NWD_STRING_H

#include <string>
using namespace std;

// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         int GCDSize = -1;
//         string GCDStr = "";
//         for (int i = 0; i < str2.length(); i++) {
//             for (int j = str2.length()-i; j > 1; j--) {
//                 cout << "i = " << i << " " << "j =" << j << endl;
//                 int found = str1.find(str2.substr(i, j), 0);
//                 cout << str2.substr(i, j) << " found: " << found << endl;
//
//                 if (found != -1 && j > GCDSize) {
//                     GCDStr = str1.substr(i + found, j);
//                     GCDSize = j;
//                 }
//             }
//         }
//         cout << "GCDSize: " << GCDSize << endl;
//         return GCDStr;
//     }
// };

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // int i = 0;
        // for (; i < max(str1.length(), str2.length()); i++) {
        //     if (str1[i] != str2[i]) break;
        // }
        // return str1.substr(0, i);

        int i = 1;
        string GDCString = "";
        for (; i < min(str1.length(), str2.length())+1; i++) {
            GDCString = str1.substr(0, i);
            cout << GDCString << " " << i << endl;
            if (str1.rfind(GDCString) == str1.length() - i && str2.rfind(GDCString) == str2.length()-i) {
                return GDCString;
            }
        }
        return GDCString;
        // while (str1.rfind(GDCString) == string::npos-GDCString.length() && str2.rfind(GDCString) == string::npos-GDCString.length()) {
        //     GDCString = str1.substr(0, i);
        // }
        //return GDCString.substr(0, i-1);
    }
};

#endif //NWD_STRING_H
