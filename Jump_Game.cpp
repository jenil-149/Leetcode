/**
 * LeetCode Problem: Jump Game
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // vector<int> dp;
    // int n;
    // bool f(int idx,vector<int> &nums){
    //     if(idx==n-1) return true;
    //     if(idx>=n) return false;

    //     if(dp[idx]!=-1) return dp[idx];

    //     for(int jump=1;jump<=nums[idx];jump++){
    //        if(f(idx+jump,nums)) return dp[idx]=true;
          
    //     }
    //     return dp[idx]=false;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int fartherstIdx=0;
        for(int i=0;i<n;i++){
            if(i>fartherstIdx) return false;

            fartherstIdx=max(fartherstIdx,i+nums[i]);
            if(fartherstIdx>=n-1) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
