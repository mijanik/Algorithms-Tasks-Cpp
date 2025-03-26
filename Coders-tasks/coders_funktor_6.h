//
// Created by Milosz on 2025-03-19.
//

#ifndef CODERS_FUNKTOR_6_H
#define CODERS_FUNKTOR_6_H

#include <iostream>

struct podzielne_przez_6 {
    bool operator() (const int x) const {
        if (x%6 == 0) return true;
        return false;
    }
};

inline void funktor_operations() {
    std::cout << podzielne_przez_6{}(6) << std::endl;
    std::cout << podzielne_przez_6{}(7) << std::endl;
}

#endif //CODERS_FUNKTOR_6_H
