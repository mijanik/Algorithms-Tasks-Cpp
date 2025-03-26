#ifndef REM_DUP_LINKED_LIST_H
#define REM_DUP_LINKED_LIST_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Funkcja usuwająca zduplikowane wartości z posortowanej listy
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;   // Wskaźnik na aktualny węzeł
        ListNode* previous = nullptr; // Wskaźnik na poprzedni węzeł

        while (current != nullptr) { // Przechodzimy przez całą listę
            // Jeśli bieżący węzeł ma taką samą wartość jak poprzedni
            if (previous != nullptr && current->val == previous->val) {
                previous->next = current->next; // Pomijamy duplikat - przepinamy wskaźniki
                delete current;                 // Usuwamy duplikat - węzeł z pamięci
                current = previous->next;       // Przechodzimy do następnego węzła
            } else {
                // Jeśli nie ma duplikatu, przesuwamy wskaźniki
                previous = current;
                current = current->next;
            }
        }
        return head; // Zwracamy zmodyfikowaną listę
    }
};

#endif //REM_DUP_LINKED_LIST_H
