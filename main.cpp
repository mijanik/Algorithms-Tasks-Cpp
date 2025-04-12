#include <iostream>
#include "Medium/longest_palindromic_substr.h"

using namespace std;

void runTest(Solution& sol, const string& input, const string& expected) {
    string result = sol.longestPalindrome(input);
    if (result == expected) {
        cout << "Test passed for input: \"" << input << "\" (output: \"" << result << "\")" << endl;
    } else {
        cout << "Test failed for input: \"" << input << "\" (expected: \"" << expected << "\", got: \"" << result << "\")" << endl;
    }
}

int main() {
    Solution sol;

    runTest(sol, "babad", "bab");    // "aba" is also valid
    runTest(sol, "cbbd", "bb");
    runTest(sol, "a", "a");
    runTest(sol, "ac", "a");         // or "c"
    runTest(sol, "racecar", "racecar");
    runTest(sol, "banana", "anana");
    runTest(sol, "forgeeksskeegfor", "geeksskeeg");
    runTest(sol, "abcd", "a");

    return 0;
}
