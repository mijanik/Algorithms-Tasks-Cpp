//
// Created by Milosz on 2025-03-24.
//

#ifndef CODERS_ITERATOR_8_H
#define CODERS_ITERATOR_8_H

#include <forward_list>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>

template <std::random_access_iterator RandomAccessIterator>
auto middle(RandomAccessIterator first, RandomAccessIterator last) {
    std::cout << "RANDOM_ACCESS_ITERATOR" << std::endl;
    // size_t size = std::distance(first, last);
    // return first + size/2
    return first + (last - first) / 2;
}


template <std::bidirectional_iterator BidirectionalIterator>
auto middle(BidirectionalIterator first, BidirectionalIterator last) {
    std::cout << "BIDIRECTIONAL_ITERATOR" << std::endl;
    size_t size = 0;
    // size = std::distance(first, last);
    for (auto it = first; it != last; ++it) size++;
    return std::next(first, size / 2);
}

template <std::forward_iterator ForwardIterator>
auto middle(ForwardIterator first, ForwardIterator last) {
    std::cout << "FORWARD_ITERATOR" << std::endl;
    size_t size = 0;
    // size = std::distance(first, last);
    for (auto it = first; it != last; ++it) size++;
    return std::next(first, size / 2);
}

inline void iterator_operations() {
    std::vector<int> test = {1, 2, 3};
    std::cout << *middle(test.begin(), test.end()) << std::endl;

    std::list<int> test_list = {1, 2, 3};
    std::cout << *middle(test_list.begin(), test_list.end()) << std::endl;

    std::forward_list<int> test_forward_list = {1, 2, 3};
    std::cout << *middle(test_forward_list.begin(), test_forward_list.end()) << std::endl;

}

#endif //CODERS_ITERATOR_8_H
