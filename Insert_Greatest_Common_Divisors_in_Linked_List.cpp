/**
 * LeetCode Problem: Insert Greatest Common Divisors in Linked List
 * Pushed by LeetCommit
 * Date: 2026-07-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;

        while(curr!=NULL){
            
            int a=prev->val;
            int b=curr->val;
            int GCD=gcd(a,b);

            ListNode* temp=new ListNode(GCD);
            prev->next=temp;
            temp->next=curr;

            prev=curr;
            curr=curr->next;

        }
        return head;

    }
};

int main() {
    return 0;
}
