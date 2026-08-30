/**
 * LeetCode Problem: Removing Minimum and Maximum From Array
 * Pushed by LeetCommit
 * Date: 2026-08-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIdx=0;
        int minIdx=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxIdx]){
                maxIdx=i;
            }
            if(nums[i]<nums[minIdx]){
                minIdx=i;
            }
        }
        int l=min(minIdx,maxIdx);
        int r=max(minIdx,maxIdx);

        return min({ r+1,
                    n-l,
                    l+1+n-r
                    });

    }
};

int main() {
    return 0;
}
