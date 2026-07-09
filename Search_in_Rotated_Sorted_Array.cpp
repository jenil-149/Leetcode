/**
 * LeetCode Problem: Search in Rotated Sorted Array
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[high]) {low=mid+1;}
                else high=mid-1;
            }

        }
        return -1;

int main() {
    return 0;
}
