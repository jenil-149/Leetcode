/**
 * LeetCode Problem: Minimum Moves to Make Array Complementary
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2+2*limit,0);

        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-1-i];

            int minVal=min(a,b)+1;
            int maxVal=max(a,b)+limit;

            diff[2]+=2;
            diff[2*limit+1]-=2;

            //for 1 move
            diff[minVal]   +=(-1);
            diff[maxVal+1] -=(-1);

            //for zero moves
            diff[a+b]   +=(-1);
            diff[a+b+1] -=(-1);
        }
        int ans=INT_MAX;

        for(int sum=2;sum<=2*limit;sum++){
            diff[sum] +=diff[sum-1];

            ans=min(ans,diff[sum]);
        }
        return ans;




        
    

    }
};

int main() {
    return 0;
}
