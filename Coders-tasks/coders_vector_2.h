//
// Created by Milosz on 2025-02-17.
//

#ifndef CODERS_VECTOR_2_H
#define CODERS_VECTOR_2_H

#include <iostream>
#include <ostream>
#include <vector>

void vector_operations() {
    std::vector v = {1, 2, 4, 5, 6}; // nowoczesne tworzenie wektora, nie trzeba <int>
    v.erase(v.begin());
    v.push_back(5);
    v.emplace_back(12);
    std::cout << "Vector size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    std::cout << "Vector elements: ";
    for (auto i : v) std::cout << i << " ";
    std::cout << std::endl;
    v.clear();
    std::cout << "Cleared vector size: " << v.size() << std::endl;

}

void vector_operations_2() {
    std::vector<int> v;
    std::cout << "Vector size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.resize(10, 5); // 10 elements with initializer 5
    std::cout << "Vector size after resize(10, 5): " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.reserve(20);
    std::cout << "Vector size after reserve(20): " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.shrink_to_fit();
    std::cout << "Vector size after shrink_to_fit(): " << v.size() << ", capacity: " << v.capacity() << std::endl;

}
#endif //CODERS_VECTOR_2_H
