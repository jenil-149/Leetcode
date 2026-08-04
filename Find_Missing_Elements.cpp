/**
 * LeetCode Problem: Find Missing Elements
 * Pushed by LeetCommit
 * Date: 2026-08-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        unordered_set<int> s(nums.begin(),nums.end());
      
        vector<int> ans;
        for(int i=nums[0]+1;i<nums[n-1];i++){
            if(!s.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;

    }
};

int main() {
    return 0;
}
