/**
 * LeetCode Problem: Path Sum II
 * Pushed by LeetCommit
 * Date: 2026-07-14
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
    vector<vector<int>> ans;

    void f(TreeNode* node,int sum,vector<int>& temp){
        if(node->left==NULL && node->right==NULL && sum==0) {
            ans.push_back(temp);
            return;
        }
        if(node->left){
            int lval=node->left->val;
            temp.push_back(lval);
            f(node->left,sum-lval,temp);
            temp.pop_back();
        }
        if(node->right){
            int rval=node->right->val;
            temp.push_back(rval);
            f(node->right,sum-rval,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       if(root==NULL) return {};
       vector<int> temp;
       temp.push_back(root->val);
       f(root,targetSum-root->val,temp);
       return ans;


    }
};

int main() {
    return 0;
}
