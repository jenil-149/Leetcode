/**
 * LeetCode Problem: House Robber II
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int rob1(vector<int>& nums) {
        
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

    int rob(vector<int>& nums) {
        int n=nums.size();
       vector<int> temp1,temp2;
       for(int i=0;i<n-1;i++){
        temp1.push_back(nums[i]);
       }
       for(int i=1;i<n;i++){
        temp2.push_back(nums[i]);
       }

       int ans1=rob1(temp1);
       int ans2=rob1(temp2);

       return max(ans1,ans2);
    }
};

int main() {
    return 0;
}
