/**
 * LeetCode Problem: Fruit Into Baskets
 * Pushed by LeetCommit
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int totalFruit(vector<int>& nums) {

        unordered_map<int,int> mp;
        int maxFruits=0;
        int l=0;

        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            
            if(mp.size()>2){             
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;  
            }
            if(mp.size()<=2) maxFruits=max(maxFruits,r-l+1);
        }
        return maxFruits;
    }
};

int main() {
    return 0;
}
