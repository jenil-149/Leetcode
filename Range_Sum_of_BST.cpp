/**
 * LeetCode Problem: Range Sum of BST
 * Pushed by LeetCommit
 * Date: 2026-07-13
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
    int ans;
    void f(TreeNode* root,int l,int h){
        if(!root) return;
        f(root->left,l,h);
        if(root->val<=h && root->val>=l) ans+=root->val;
        f(root->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        f(root,low,high);
        return ans;
    }
};

int main() {
    return 0;
}
