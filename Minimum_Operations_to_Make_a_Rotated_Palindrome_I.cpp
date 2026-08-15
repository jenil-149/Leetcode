/**
 * LeetCode Problem: Minimum Operations to Make a Rotated Palindrome I
 * Pushed by LeetCommit
 * Date: 2026-08-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            string temp=s;
            int currAns=r;
            rotate(temp.begin(),temp.begin()+r,temp.end());

            for(int i=0;i<n/2;i++){
                char c1=temp[i];
                char c2=temp[n-1-i];

                int diff=(int)abs(c2-c1);
                currAns+=min(26-diff,diff);
            }
            ans=min(ans,currAns);
        }

        return ans;

    }
};

int main() {
    return 0;
}
