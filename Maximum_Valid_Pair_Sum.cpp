/**
 * LeetCode Problem: Maximum Valid Pair Sum
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        vector<int> mx(n);
        mx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],nums[i]);
        }
        for(int i=0;i<n-k;i++){
           ans=max(ans,nums[i]+mx[i+k]);
        }
        return ans;
    }
};
// brutforce will result in TLE

int main() {
    return 0;
}
