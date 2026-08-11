/**
 * LeetCode Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Pushed by LeetCommit
 * Date: 2026-08-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int prefix=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) prefix+=nums[i];
            else break;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        while(s.count(prefix)){
            prefix++;
        }
        return prefix;

    }
};

int main() {
    return 0;
}
