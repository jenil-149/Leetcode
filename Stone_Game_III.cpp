/**
 * LeetCode Problem: Stone Game III
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // int n;
    // vector<int> dp;
    // int f(int idx,vector<int>& nums){
    //     if(idx>=n){
    //         return 0; 
    //     }
    //     if(dp[idx]!=INT_MIN) return dp[idx];

    //     int takeTwo=INT_MIN;
    //     int takeThree=INT_MIN;

    //     int takeOne=nums[idx]-f(idx+1,nums);
    //     if(idx+1<n)
    //         takeTwo=nums[idx]+nums[idx+1]-f(idx+2,nums);
    //     if(idx+2<n)
    //         takeThree=nums[idx]+nums[idx+1]+nums[idx+2]-f(idx+3,nums);

    //     return dp[idx]=max({takeOne,takeTwo,takeThree});    

    // }
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+3,0);

        for(int idx=n-1;idx>=0;idx--){

            int takeTwo=INT_MIN;
            int takeThree=INT_MIN;

            int takeOne=nums[idx]-dp[idx+1];
            if(idx+1<n)
                takeTwo=nums[idx]+nums[idx+1]-dp[idx+2];
            if(idx+2<n)
                takeThree=nums[idx]+nums[idx+1]+nums[idx+2]-dp[idx+3];

            dp[idx]=max({takeOne,takeTwo,takeThree});
        }


        if(dp[0]==0) return "Tie";
        else if(dp[0]>0) return "Alice";
        else return "Bob";
    }
};

int main() {
    return 0;
}
