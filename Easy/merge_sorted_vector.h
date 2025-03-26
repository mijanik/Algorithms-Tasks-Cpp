//
// Created by Milosz on 2025-02-28.
//

#ifndef MERGE_SORTED_VECTOR_H
#define MERGE_SORTED_VECTOR_H

#include <vector>

// Mergowanie obu wektorów do wektora nums1
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Gdy pierwszy wektor jest pusty
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        //                V
        // nums1 = [1, 2, 3, 0, 0]
        auto current_num1_element = std::next(nums1.rbegin(), n);
        //             V
        // nums2 = [2, 4]
        auto current_num2_element = nums2.rbegin();

        for (auto it = nums1.rbegin(); it != nums1.rend(); it++) { // idziemy od końca pierwszego wektora

            // Jeśli żaden z 2 iteratorów nie doszedł do końca, to na bieżące miejsce wrzucamy większy
            if (current_num1_element < nums1.rend() && current_num2_element < nums2.rend()) {
                if (*current_num1_element > *current_num2_element) {
                    *it = *current_num1_element;
                    current_num1_element++;
                }
                else {
                    *it = *current_num2_element;
                    current_num2_element++;
                }
            }
            else if (current_num2_element == nums2.rend()) { //jeśli z drugiego już wszystko przerzuciliśmy to gotowe
                return;
            }
            // Jeśli zostały same rzeczy w drugim
            else if (current_num2_element < nums2.rend() && current_num1_element == nums1.rend()) {
                *it = *current_num2_element;
                current_num2_element++;
            }
        }
    }
};

#endif //MERGE_SORTED_VECTOR_H
