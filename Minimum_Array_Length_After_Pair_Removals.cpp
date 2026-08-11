/**
 * LeetCode Problem: Minimum Array Length After Pair Removals
 * Pushed by LeetCommit
 * Date: 2026-08-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=(n+1)/2;

        while(l<n/2 && r<n){
            if(nums[l]<nums[r]){
                l++;
                r++;
            }else{
                r++;
            }

        }
        return n-2*l;
    }
};

int main() {
    return 0;
}
