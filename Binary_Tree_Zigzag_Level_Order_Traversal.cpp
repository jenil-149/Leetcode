/**
 * LeetCode Problem: Binary Tree Zigzag Level Order Traversal
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        bool lTor=true;
        while(!q.empty()){

            vector<int> temp;
            int s=q.size();

            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                int value=node->val;
                temp.push_back(value);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            
            }
            if(!lTor) {
                reverse(temp.begin(),temp.end());
            }
            lTor=!lTor;
            ans.push_back(temp);
                
        }
        return ans;
    }
};

int main() {
    return 0;
}
