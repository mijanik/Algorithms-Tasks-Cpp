#include <iostream>
#include <cassert>
#include "Medium/longest_substr_wo_repeat.h"
using namespace std;

void runTest(Solution& sol, const string& input, int expected) {
    int result = sol.lengthOfLongestSubstring(input);
    if (result == expected) {
        cout << "✅ Test passed for input: \"" << input << "\" (output: " << result << ")" << endl;
    } else {
        cout << "❌ Test failed for input: \"" << input << "\" (expected: " << expected << ", got: " << result << ")" << endl;
    }
}

int main() {
    Solution sol;

    runTest(sol, "abcabcbb", 3);    // "abc"
    runTest(sol, "bbbbb", 1);       // "b"
    runTest(sol, "pwwkew", 3);      // "wke"
    runTest(sol, "", 0);            // empty string
    runTest(sol, "abcdefg", 7);     // all unique
    runTest(sol, "dvdf", 3);        // "vdf"
    runTest(sol, "a!@#a$%^", 7);    // "!@#a$%^"

    return 0;
}