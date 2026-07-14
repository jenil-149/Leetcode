/**
 * LeetCode Problem: Binary Tree Level Order Traversal
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            
        }
        return ans;
        
    }
};

int main() {
    return 0;
}
