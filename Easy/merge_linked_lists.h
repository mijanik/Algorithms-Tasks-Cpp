//
// Created by Milosz on 2025-01-20.
//

#ifndef MERGE_LINKED_LISTS_H
#define MERGE_LINKED_LISTS_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        if ((list1 != nullptr && list2 != nullptr && list1->val <= list2->val) ||
            (list1 != nullptr && list2 == nullptr)){
            head = list1;
            list1 = list1->next;
        }
        else if ((list1 != nullptr && list2 != nullptr && list1->val > list2->val) ||
            (list1 == nullptr && list2 != nullptr)){
            head = list2;
            list2 = list2->next;
        }
        ListNode* current = head;
        while (list1 != nullptr || list2 != nullptr) {
            if ((list1 != nullptr && list2 != nullptr && list1->val <= list2->val) ||
                (list1 != nullptr && list2 == nullptr)) {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
            else if ((list1 != nullptr && list2 != nullptr && list1->val > list2->val) ||
            (list1 == nullptr && list2 != nullptr)) {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }
        return head;
    }
};

#endif //MERGE_LINKED_LISTS_H
