/**
 * LeetCode Problem: Recover Binary Search Tree
 * Pushed by LeetCommit
 * Date: 2026-07-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

     void helper(TreeNode* node) {
        if (node==NULL) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;

        helper(node->right);
    }

    void recoverTree(TreeNode* root) {
        helper(root);
        // Swap the values of the two wrong nodes
        swap(first->val, second->val);
    }
 
};

int main() {
    return 0;
}
