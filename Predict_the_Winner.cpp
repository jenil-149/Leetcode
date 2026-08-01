/**
 * LeetCode Problem: Predict the Winner
 * Pushed by LeetCommit
 * Date: 2026-08-01
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // tarack the max diffrence curr player can achieve by takieng left/right 
    //we subtract f(..) because the next move would be of another player

    typedef long long ll;
    vector<vector<int>> dp;
    
    int f(int l,int r,vector<int> & nums){
        if(l==r) return nums[l];
        if(dp[l][r]!=-1) return dp[l][r];

        int takeLeft=nums[l]-f(l+1,r,nums);
        int takeRight=nums[r]-f(l,r-1,nums);

        return dp[l][r]=max(takeLeft,takeRight);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return f(0,n-1,nums)>=0;
    }

//First approach

    // bool f(int l,int r,vector<int>& nums,ll sum1,ll sum2,bool player1){
    //     if(l>r) {
    //         if(sum1>=sum2) return true;
    //         else return false;
    //     }
    //     if(player1){
    //         bool front=f(l+1,r,nums,sum1+nums[l],sum2,0);
    //         bool back=f(l,r-1,nums,sum1+nums[r],sum2,0);
    //         return front||back;
    //     }else{
    //         bool front=f(l+1,r,nums,sum1,sum2+nums[l],1);
    //         bool back=f(l,r-1,nums,sum1,sum2+nums[r],1);
    //         return front && back;
    //     }

    // }
};

int main() {
    return 0;
}
