/**
 * LeetCode Problem: Jump Game II
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    //DP solution
    // vector<int> dp;
    // int n;
    // int  f(int idx,vector<int> &nums){

    //     if(idx>=n-1) return 0;

    //     if(dp[idx]!=-1) return dp[idx];
    //     int ans=INT_MAX;

    //     for(int jump=1;jump<=nums[idx];jump++){

    //        if(idx+jump<n){
    //         int temp=f(idx+jump,nums);
    //         if(temp!=INT_MAX) ans=min(ans,1+temp);
    //       }

    //     }
    //     return dp[idx]=ans;
    // }

  //GREEDY APPROACH  
int jump(vector<int>& nums) {

       int n=nums.size();
        int jumps=0;
        int l=0,r=0;

        for(int i=0;i<n-1;i++){
            r=max(r,i+nums[i]);

            if(i==l) {
                jumps++;
                l=r;
            }
        }
        return jumps;
    }
};

int main() {
    return 0;
}
