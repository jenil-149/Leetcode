/**
 * LeetCode Problem: Count Nodes Equal to Average of Subtree
 * Pushed by LeetCommit
 * Date: 2026-09-10
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
    int ans=0;

    pair<int,int> f(TreeNode * root){
        if(root==NULL) return {0,0};

        pair<int,int> left=f(root->left);
        pair<int,int> right=f(root->right);

        int nodeSum=left.first+right.first+root->val;
        int cnt=left.second+right.second+1;

        if(root->val==(nodeSum/cnt)) ans++;

        return {nodeSum,cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        f(root);

        return ans;
    }
};

int main() {
    return 0;
}
