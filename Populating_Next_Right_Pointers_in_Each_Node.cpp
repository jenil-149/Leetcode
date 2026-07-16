/**
 * LeetCode Problem: Populating Next Right Pointers in Each Node
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return {};

        queue<Node*> q;
        q.push(root);
    
        while(!q.empty()){

            int s=q.size();
            Node* prev=NULL;
            for(int i=0;i<s;i++){
                Node* node=q.front();
                q.pop();

                if(prev) prev->next=node;
                prev=node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            
            }
            prev->next=NULL;
                
        }
        return root;
    }
};

int main() {
    return 0;
}
