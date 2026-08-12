/**
 * LeetCode Problem: Length of Longest Subarray With at Most K Frequency
 * Pushed by LeetCommit
 * Date: 2026-08-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l=0;
        int overK=0;
        for(int r=0;r<nums.size();r++){
            freq[nums[r]]++;
            if(freq[nums[r]]==k+1) overK++;
            if(overK>0) {
                freq[nums[l]]--;
                if(freq[nums[l]]==k) overK--;
                l++;
            }
        }
        return nums.size()-l;
    }
};

int main() {
    return 0;
}
