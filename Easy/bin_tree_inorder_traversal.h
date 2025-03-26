//
// Created by Milosz on 2025-01-24.
//

#ifndef BIN_TREE_INORDER_TRAVERSAL_H
#define BIN_TREE_INORDER_TRAVERSAL_H

#include <vector>

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

    void inorderTraversalRecursive(TreeNode* root, std::vector<int> &nodes) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            inorderTraversalRecursive(root->left, nodes);
        }
        if (root->right != nullptr) {
            nodes.push_back(root->val);
            inorderTraversalRecursive(root->right, nodes);
        }
        if (root->right == nullptr) { // jeśli oba są null lub już był w lewym a prawy to null
            nodes.push_back(root->val);
        }
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorderTraversalRecursive(root, res);
        return res;
    }
};

#endif //BIN_TREE_INORDER_TRAVERSAL_H
