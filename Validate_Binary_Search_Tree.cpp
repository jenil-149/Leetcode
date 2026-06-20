/**
 * LeetCode Problem: Validate Binary Search Tree
 * Pushed by LeetCommit
 * Date: 2026-06-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

        if(root->val <= mn ||root->val >= mx)
            return false;

        return check(root->left,mn, root->val)
            && check(root->right,root->val,mx);
    }

    bool isValidBST(TreeNode* root)
    {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
            return true;
        if(root == NULL)
    {
};
    bool check(TreeNode* root,long long mn,long long mx)
public:
class Solution {

int main() {
    return 0;
}
