//
// Created by Milosz on 2025-03-01.
//

#ifndef SYMMETRIC_BINARY_TRY_H
#define SYMMETRIC_BINARY_TRY_H

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
    bool Symmetric = true;
    bool isSymmetricTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;

        // Jeśli tylko jeden ma którąś stronę null
        if ((p->left == nullptr && q->right != nullptr) ||
            (p->right == nullptr && q->left != nullptr) ||
            (p->left != nullptr && q->right == nullptr) ||
            (p->right != nullptr && q->left == nullptr)) return false;

        // sprawdzanie lewej strony
        if (p->left != nullptr && q->right != nullptr) {
            Symmetric = isSymmetricTree(p->left, q->right);
        }

        // sprawdzanie prawej strony
        if (p->right != nullptr && q->left != nullptr) {
            Symmetric = isSymmetricTree(p->right, q->left);
        }

        // jeśli w obu obie strony to null
        if (p->left == nullptr && p->right == nullptr &&
            q->left == nullptr && q->right == nullptr) return Symmetric;

        return Symmetric;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricTree(root->left, root->right);
    }
};

#endif //SYMMETRIC_BINARY_TRY_H
