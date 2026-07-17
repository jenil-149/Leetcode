/**
 * LeetCode Problem: Binary Tree Maximum Path Sum
 * Pushed by LeetCommit
 * Date: 2026-07-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx=INT_MIN;
    int f(TreeNode* node){
        if(node==NULL) return 0;
        
        int leftSum=max(0,f(node->left));
        int rightSum=max(0,f(node->right));

        mx=max(mx,(node->val)+leftSum+rightSum);

        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return mx;
    }
};

int main() {
    return 0;
}
