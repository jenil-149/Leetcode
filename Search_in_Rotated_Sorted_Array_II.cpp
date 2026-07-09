/**
 * LeetCode Problem: Search in Rotated Sorted Array II
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return true;

            // Can't determine the sorted half
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }

            // Left half is sorted
            else if(nums[low] <= nums[mid]){

                if(nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;

int main() {
    return 0;
}
