/**
 * LeetCode Problem: Find the Number of Subsequences With Equal GCD
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    const int  MOD=1000000007;
    // int f(int idx,int gcd1,int gcd2,vector<int> &nums){
    //     if(idx<0 ) return (gcd1==gcd2 && gcd1!=0);
       
    //     int a1=f(idx-1,gcd1,gcd2,nums)%MOD;
    //     int a2=f(idx-1,gcd(gcd1,nums[idx]),gcd2,nums)%MOD;
    //     int a3=f(idx-1,gcd1,gcd(gcd2,nums[idx]),nums)%MOD;

    //     return (a1+a2+a3)%MOD;
    // }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(auto num: nums) mx=max(mx,num);
        vector<vector<int>> prev(mx+1,vector<int>(mx+1,0));
        
        prev[0][0]=1;

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            vector<vector<int>> curr(mx+1,vector<int>(mx+1,0));
            for(int g1 = 0; g1 <= mx; g1++) {
                for(int g2 = 0; g2 <= mx; g2++) {

                    if(prev[g1][g2] == 0) continue;
                    int ways = prev[g1][g2];

                     // Ignore
                     curr[g1][g2] =(curr[g1][g2] + ways) % MOD;

                    // First subsequence
                    int ng1 = gcd(g1, x);
                    curr[ng1][g2] =(curr[ng1][g2] + ways) % MOD;

                    // Second subsequence
                    int ng2 = gcd(g2, x);
                    curr[g1][ng2] =(curr[g1][ng2] + ways) % MOD;
                }
            }
            prev=curr;
        }
        long long ans=0;
        for(int g=1;g<=mx;g++){
            ans=(ans+prev[g][g])%MOD;
        }
        return ans;
        
    }
};


int main() {
    return 0;
}
