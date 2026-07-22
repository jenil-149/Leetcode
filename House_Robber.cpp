/**
 * LeetCode Problem: House Robber
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // int f(int i,vector<int> & nums){
    //     if(i<0) return 0;
    //     int notTake=f(i-1,nums);
    //     int take=nums[i]+f(i-2,nums);

    //     return max(take,notTake); 
    // }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
    
        for(int i=1;i<n;i++){
            int curr=0;

            int notTake=prev1;
            int take=nums[i];
            if(i>1)  take+=prev2;

            curr=max(take,notTake);

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};

int main() {
    return 0;
}
