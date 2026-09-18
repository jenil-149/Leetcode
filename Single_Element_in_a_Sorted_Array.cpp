/**
 * LeetCode Problem: Single Element in a Sorted Array
 * Pushed by LeetCommit
 * Date: 2026-09-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;

            if(mid%2==0 ){
                if(nums[mid]!=nums[mid+1]) r=mid;
                else l=mid+2;
            }else{
                if(nums[mid]!=nums[mid-1]) r=mid;
                else l=mid+1;
            }
        }
        return nums[l];
    }
};


int main() {
    return 0;
}
