/**
 * LeetCode Problem: Kth Smallest Element in a BST
 * Pushed by LeetCommit
 * Date: 2026-06-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    void dfs(TreeNode* root,int &cnt,int k,int &ans){
        if(root==NULL) return;
        dfs(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k) ans=root->val;
        dfs(root->right,cnt,k,ans); 
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int cnt=0,ans=0;
       dfs(root,cnt,k,ans);
       return ans; 
    }
};

int main() {
    return 0;
}
