/**
 * LeetCode Problem: Maximum Depth of Binary Tree
 * Pushed by LeetCommit
 * Date: 2026-06-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
1class Solution {
2public:
3    int maxDepth(TreeNode* root) {
4        if(root==NULL) return 0;
5        int lh=maxDepth(root->left);
6        int rh=maxDepth(root->right);
7        return 1+max(rh,lh);
8    }
9};
10

int main() {
    return 0;
}
