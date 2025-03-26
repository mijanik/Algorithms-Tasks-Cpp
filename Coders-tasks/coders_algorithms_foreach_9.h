//
// Created by Milosz on 2025-03-26.
//

#ifndef CODERS_ALGORITHMS_FOREACH_9_H
#define CODERS_ALGORITHMS_FOREACH_9_H

#include <vector>
#include <iostream>
#include <algorithm>

inline void foreach_task() {
    std::vector v = {0, 1, 2, 3, 4 ,5 ,6 ,7 ,8 ,9};
    auto lambda_catch_vector = [&v]() {
        for (auto const it: v) std::cout << it << " ";
        std::cout << std::endl;
    };
    auto lambda_print_obj = [](int obj) {
        std::cout << obj << " ";
    };

    lambda_catch_vector();
    std::for_each(v.begin(), v.end(), lambda_print_obj);
}

#endif //CODERS_ALGORITHMS_FOREACH_9_H
