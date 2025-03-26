//
// Created by Milosz on 2025-03-03.
//

#ifndef ADD_REVERSE_LINK_LISTS_VAL_H
#define ADD_REVERSE_LINK_LISTS_VAL_H

#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result_head = new ListNode;
        ListNode* result_temp = result_head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            result_temp->val = 0;
            if (l1 != nullptr) result_temp->val += l1->val;
            if (l2 != nullptr) result_temp->val += l2->val;
            result_temp->val += carry;
            carry = result_temp->val / 10;
            result_temp->val %= 10;

            if (l1 != nullptr && l2 != nullptr && carry == 0) {
                if (l1->next == nullptr && l2->next == nullptr) return result_head;
            }
            else if (l1 == nullptr && l2 != nullptr && carry == 0) {
                if (l2->next == nullptr) return result_head;
            }
            else if (l1 != nullptr && l2 == nullptr && carry == 0) {
                if (l1->next == nullptr) return result_head;
            }
            else if (l1 == nullptr && l2 == nullptr && carry == 0) {
                return result_head;
            }

            result_temp->next = new ListNode;
            result_temp = result_temp->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return result_head;
    }
};

#endif //ADD_REVERSE_LINK_LISTS_VAL_H
