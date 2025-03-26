//
// Created by Milosz on 2025-02-18.
//

#ifndef CODERS_ARRAY_3_H
#define CODERS_ARRAY_3_H

#include <iostream>
#include <array>


void array_operations(){
    std::array<int, 10> arr{};
    arr.fill(5);
    arr[3] = 3;
    std::array<int, 10> arr2{};
    arr.swap(arr2);

    for ( auto i : arr) std::cout << i << " ";
    std::cout<<std::endl;
    for ( auto i : arr2) std::cout << i << " ";
}

#endif //CODERS_ARRAY_3_H
