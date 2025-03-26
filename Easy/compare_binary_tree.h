//
// Created by Milosz on 2025-01-24.
//

#ifndef COMPARE_BINARY_TREE_H
#define COMPARE_BINARY_TREE_H

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool same = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;

        // Jeśli tylko jeden ma którąś stronę null
        if ((p->left == nullptr && q->left != nullptr) ||
            (p->right == nullptr && q->right != nullptr) ||
            (p->left != nullptr && q->left == nullptr) ||
            (p->right != nullptr && q->right == nullptr)) return false;

        // sprawdzanie lewej strony
        if (p->left != nullptr && q->left != nullptr) {
            same = isSameTree(p->left, q->left);
        }

        // sprawdzanie prawej strony
        if (p->right != nullptr && q->right != nullptr) {
            same = isSameTree(p->right, q->right);
        }

        // jeśli w obu obie strony to null
        if (p->left == nullptr && p->right == nullptr &&
            q->left == nullptr && q->right == nullptr) return same;

        return same;
    }
};

#endif //COMPARE_BINARY_TREE_H
