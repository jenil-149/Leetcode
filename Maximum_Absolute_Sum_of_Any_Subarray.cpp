/**
 * LeetCode Problem: Maximum Absolute Sum of Any Subarray
 * Pushed by LeetCommit
 * Date: 2026-09-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
 
    int maxAbsoluteSum(vector<int>& nums) {
        int mxSum=0;
        int mnSum=0;
        int currMaxSum=0;
        int currMinSum=0;

        for(int i=0;i<nums.size();i++){
            currMaxSum+=nums[i];
            if(currMaxSum<0) currMaxSum=0;
            mxSum=max(currMaxSum,mxSum);

            currMinSum+=nums[i];
            if(currMinSum>0) currMinSum=0;
            mnSum=min(currMinSum,mnSum);

        }
        return max(abs(mnSum),mxSum);
    }
};

int main() {
    return 0;
}
