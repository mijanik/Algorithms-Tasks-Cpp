//
// Created by Milosz on 2025-04-07.
//

#ifndef CODERS_ALGORITHMS_10_H
#define CODERS_ALGORITHMS_10_H

#include <algorithm>
#include <vector>
#include <iostream>

// Algorytmy niemodyfikujące sekwencji
inline void non_modifying_algorithms() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; // testowy wektor

    // Policz, ile jest elementów większych lub równych 5
    std::cout<<"number of numbers greater or equal to 5: "<<
        std::count_if(v.begin(), v.end(), [](const int i) { return i>=5; })
        << std::endl;

    // Sprawdź, czy istnieje element mniejszy od 1
    std::cout<<"Check if there is an element smaller than 1: "<< std::boolalpha <<
        std::any_of(v.begin(), v.end(), [](const int i) { return i<1; })
    << std::endl;

    // Sprawdź, czy wszystkie elementy są większe od 1
    std::cout<<"Check if all elements are greater than 1: "<< std::boolalpha <<
        std::all_of(v.begin(), v.end(), [](const int i) { return i>1; })
    << std::endl;

    // Znajdź wszystkie elementy większe od 6 i wypisz je
    //TODO
    //std::find(v.begin(), v.end(), [](int e){return e>6;});

    // Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
    //TODO

    // Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
    //TODO
}

#endif //CODERS_ALGORITHMS_10_H
