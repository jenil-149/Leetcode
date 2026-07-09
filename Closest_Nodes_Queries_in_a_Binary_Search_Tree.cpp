/**
 * LeetCode Problem: Closest Nodes Queries in a Binary Search Tree
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    void inOrderTraversal(TreeNode* root,vector<int>& inOrder){
        if(root==NULL) return;

        inOrderTraversal(root->left,inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right,inOrder);

    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inOrder;
        inOrderTraversal(root,inOrder);

        vector<vector<int>> ans;
        for(int i=0;i<queries.size();i++){

            int lb=lower_bound(inOrder.begin(),inOrder.end(),queries[i])-inOrder.begin();
            
            int mini=-1;
            int maxi=-1;
           
            if(lb==inOrder.size())
            {
                mini=inOrder[lb-1];
            }
            else if(inOrder[lb]==queries[i]) {
                mini=maxi=queries[i];
            }
            else if(lb==0){
                maxi=inOrder[lb];
            }
           else{
                mini=inOrder[lb-1];
                maxi=inOrder[lb];
            }
            ans.push_back({mini,maxi});

        }
        return ans;
    }
};

int main() {
    return 0;
}
