/**
 * LeetCode Problem: Flatten Binary Tree to Linked List
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
   
    void flatten(TreeNode* root) {

        TreeNode* curr=root;
        while(curr){
            // if leftsubtree exits
            if(curr->left){
                
                TreeNode* pre=curr->left;
                // go to extreme right of left subtree
                while(pre->right){
                    pre=pre->right;
                }
                // extreme right point to curr right
                pre->right=curr->right;
                // curr right will point to its left
                curr->right=curr->left;
                curr->left=NULL;

            }
            // move to its right 
            curr=curr->right;
        }
    }
};

// recursice soln: first flatten right tree then left

// class Solution {
// public:
//    TreeNode* prev=NULL;
//     void flatten(TreeNode* root) {
//         if(root==NULL) return;

//         flatten(root->right);
//         flatten(root->left);

//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }
// };

int main() {
    return 0;
}
