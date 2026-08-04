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
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());

        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        for(int i=mn+1;i<mx;i++){
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
