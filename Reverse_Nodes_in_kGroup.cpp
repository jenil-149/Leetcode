/**
 * LeetCode Problem: Reverse Nodes in k-Group
 * Pushed by LeetCommit
 * Date: 2026-09-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    ListNode* reverseLL(ListNode* curr,ListNode* end){

        ListNode* prev=NULL;
        while(curr!=end){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL) return head;
        ListNode* tail=head;

        for(int i=0;i<k;i++){

            if(tail==NULL) return head;
            tail=tail->next;
        }

        ListNode* newHead = reverseLL(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }
};

int main() {
    return 0;
}
