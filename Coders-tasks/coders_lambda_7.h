//
// Created by Milosz on 2025-03-21.
//

#ifndef CODERS_LAMBDA_7_H
#define CODERS_LAMBDA_7_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


inline void lambda_operations() {
    auto lambda_iloczyn = [](const int x, const int y){return x*y;};
    std::cout << "lambda_iloczyn: " << lambda_iloczyn(2, 3) << std::endl;
    auto lambda_cudzyslow = [](std::string x){x.insert(0, 1, '\"');
                                                     x.push_back('\"');
                                                     return x;};
    std::cout << "lambda_cudzyslow: " << lambda_cudzyslow("krowa") << std::endl;

    int counter = 1;
    auto lambda_gwiazdka = [&counter]() {
        for (int i = 0; i < counter; i++)
            std::cout << '*';
        std::cout << std::endl;
        counter++;
    };
    lambda_gwiazdka();
    lambda_gwiazdka();
    lambda_gwiazdka();

}

inline void lambda_operations2() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto lambda_przechwyc_wektor = [v](){for (auto it : v) std::cout << it << ' ';};
    lambda_przechwyc_wektor();
    auto lambda_wypisz_int = [](int x){std::cout << x;};

    std::for_each(v.begin(), v.end(), lambda_wypisz_int);
}
#endif //CODERS_LAMBDA_7_H
