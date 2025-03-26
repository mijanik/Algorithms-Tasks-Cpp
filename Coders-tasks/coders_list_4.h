//
// Created by Milosz on 2025-02-24.
//

#ifndef CODERS_LIST_4_H
#define CODERS_LIST_4_H

#include <list>
#include <iostream>
#include <algorithm>
#include <array>

inline void list_operations() {
    std::list lista = {0, 1, 2, 3, 4, 5};
    for (auto it : lista) std::cout << it << " ";
    std::cout << std::endl;
    // usuwanie trzeciego elementu:
    //lista.remove(2);
    auto trzeci_element = lista.begin();
    std::advance(trzeci_element, 2);
    lista.erase(trzeci_element);
    lista.push_front(10);
    lista.push_back(10);
    for (auto it : lista) std::cout << it << " ";
    std::cout << std::endl;

    auto czwarty_element = lista.begin();
    std::advance(czwarty_element, 3);
    lista.insert(czwarty_element, 20);

    std::array<int, 8> przepisane{};
    //std::copy(lista.begin(), lista.end(), przepisane.begin());
    int i = 0;
    for (auto it : lista) {
        przepisane[i] = it;
        i++;
    }
    for (auto it : przepisane) std::cout << it << " ";
    std::cout << std::endl;


}

#endif //CODERS_LIST_4_H
