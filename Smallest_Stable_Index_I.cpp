/**
 * LeetCode Problem: Smallest Stable Index I
 * Pushed by LeetCommit
 * Date: 2026-09-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> mn(n);
        mn[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            mn[i]=min(nums[i],mn[i+1]);
        }

        int mx=nums[0];
        for(int i=0;i<n;i++){

            mx=max(nums[i],mx);
            if(mx-mn[i]<=k) return i;
        }

        return -1;

    }
};

int main() {
    return 0;
}
