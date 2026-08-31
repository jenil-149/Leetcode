/**
 * LeetCode Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Pushed by LeetCommit
 * Date: 2026-08-31
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1;
        ListNode* prev=head;
        ListNode* curr=head->next;

        vector<int> a;
        while(curr->next!=NULL){
            int currVal=curr->val;
            int prevVal=prev->val;
            int nextVal=curr->next->val;

            if((currVal<prevVal && currVal<nextVal) || (currVal>prevVal && currVal>nextVal)) a.push_back(i);
            prev=curr;
            curr=curr->next;
            i++;
        }
        int n=a.size();
        if(n<=1) return {-1,-1};
        int mn=INT_MAX;

        for(int i=1;i<n;i++)
        {
            mn=min(a[i]-a[i-1],mn);
        }
        return {mn,a[n-1]-a[0]};

    }
};

int main() {
    return 0;
}
