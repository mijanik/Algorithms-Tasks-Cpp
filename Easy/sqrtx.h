//
// Created by Milosz on 2025-01-30.
//

#ifndef SQRTX_H
#define SQRTX_H

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            unsigned long long mid = (left + right) / 2; // liczymy środek
            if ( mid * mid == x  || ( mid * mid < x && (mid+1) * (mid+1) > x ) )
                return mid;   // Jesli srodek to idealnie pierwiastek lub zwiekszony o 1 juz przekroczy
            else if ( mid * mid > x ) {
                right = mid - 1; // Jesli pierwiastek wychodzi za duzy to bierzemy lewy zakres
            }
            else if ( mid * mid < x ) {
                left = mid + 1;  // A jeśli za mały to prawy zakres
            }
        }
        return -1;
    }
};

#endif //SQRTX_H
