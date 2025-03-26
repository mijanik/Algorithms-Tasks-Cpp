//
// Created by Milosz on 2025-02-20.
//

#ifndef REMOVE_VEC_ELEMENT_H
#define REMOVE_VEC_ELEMENT_H

#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int removed = 0; // ilość "usuniętych" elementów (przeniesionych na koniec)
        auto end = nums.end()-1; // ustawiamy wskaźnik końca dobrych na ostatni element
        for (auto i = nums.begin(); i <= end; ++i) {
            if (*i == val) { // jeśli bieżący element to jest ten zły
                while (*end == val && end > i) { // dopóki na końcu jest zła liczba
                    --end; //przesuwamy koniec w lewo
                    removed++; // a ilość usunietych zwiększamy
                }
                std::swap(*i, *end);
                removed++;
                --end;
            }
        }
        //nums.erase(nums.end()-removed, nums.end()); // usuwanie koncowych ale niepotrzebne
        return nums.size() - removed; //zwracamy ilość dobrych elementów

    }
};

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int index = 0;
//         for(int i = 0; i< nums.size(); i++){
//             if(nums[i] != val){
//                 nums[index] = nums[i];
//                 index++;
//             }
//         }
//         return index;
//     }
// };

#endif //REMOVE_VEC_ELEMENT_H
