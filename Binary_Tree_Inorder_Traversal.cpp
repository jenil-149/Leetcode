/**
 * LeetCode Problem: Binary Tree Inorder Traversal
 * Pushed by LeetCommit
 * Date: 2026-06-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    void f(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        f(root->left,ans);
        ans.push_back(root->val);
        f(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        f(root,ans);
        return ans;
        
    }
};

int main() {
    return 0;
}
