//
// Created by Milosz on 2025-03-13.
//

#ifndef CODERS_DEQUE_5_H
#define CODERS_DEQUE_5_H

#include <deque>
#include <iostream>

inline void deque_operations() {
    std::deque<int> kolejka; //stwórz pustą kolejkę
    kolejka.insert(kolejka.end(), {1, 2, 3, 4, 5}); //dodanie 5 wartości

    for (const auto it : kolejka) std::cout << it << " ";
    std::cout << std::endl;

    kolejka.erase(kolejka.begin()+1); //usuń drugi element
    kolejka.erase(kolejka.begin()+2); //usuń czwarty element (który jest teraz trzeci)

    //dodaj na początek i na koniec 30
    kolejka.emplace_front(30);
    kolejka.emplace_back(30);

    for (const auto it : kolejka) std::cout << it << " ";
    std::cout << std::endl;

    kolejka.insert(kolejka.begin()+3, 20); //dodaj na 4 pozycji liczbę 20

    for (const auto it : kolejka) std::cout << it << " ";
    std::cout << std::endl;

}

#endif //CODERS_DEQUE_5_H
