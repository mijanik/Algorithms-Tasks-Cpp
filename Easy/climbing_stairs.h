//
// Created by Milosz on 2025-01-30.
//

#ifndef CLIMBING_STAIRS_H
#define CLIMBING_STAIRS_H

class Solution {
public:
    int climbStairs(int n) {
        // if (n <= 1) return 1;
        // return climbStairs(n - 1) + climbStairs(n - 2); //rekursywnie

        if (n<=1) return 1;
        if (n==2) return 2;
        int a = 1, b = 2; // b to fib(2), a to fib(1)

        for (int i = 3; i <= n; i++) {
            b = b + a; // b to suma poprzedniego b i a
            a = b - a; //a to poprzednie b
        }
        return b;
    }
};

// n=0 -> można wejść na 1 sposób
// n=1 -> można wejść na 1 sposób: 1
// n=2 -> można wejść na 2 sposoby: 1+1 lub 2
// n=3 -> można wejść na 3 sposoby: 1+1+1 1+2 2+1
// n=4 -> można wejść na 5 sposobów 1+1+1+1 1+1+2 1+2+1 2+1+1 2+2

#endif //CLIMBING_STAIRS_H
