/**
 * LeetCode Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Pushed by LeetCommit
 * Date: 2026-07-10
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
    TreeNode* helper(vector<int>& preorder,int start,int end,int &rootIdx,unordered_map<int,int> &mp){
        if(start>end) return NULL;

        int val=preorder[rootIdx];
        TreeNode* node = new TreeNode(val);
        rootIdx++;
        
        int inOrder_rootIdx=mp[val];
        
        node->left=helper(preorder,start,inOrder_rootIdx-1,rootIdx,mp);
        node->right=helper(preorder,inOrder_rootIdx+1,end,rootIdx,mp);

        return node;
    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n=preorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int rootIdx=0;
        return helper(preorder,0,n-1,rootIdx,mp);
    }
};

int main() {
    return 0;
}
