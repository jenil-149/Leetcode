/**
 * LeetCode Problem: Subsets II
 * Pushed by LeetCommit
 * Date: 2026-07-27
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;

        for(int mask=0;mask<(1<<n);mask++){
            vector<int> temp;

            for(int i=0;i<n;i++){

                if(mask & (1<<i)) 
                    temp.push_back(nums[i]);

            }
            ans.insert(temp);
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

int main() {
    return 0;
}
