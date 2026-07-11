/**
 * LeetCode Problem: Contiguous Array
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        //store the sum and idx
        unordered_map<int,int> mp;
        //zero sum at -1th idx
        mp[0]=-1;
        //current sum
        int sum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) sum--;
            else sum++;
            //if the same sum is present we can say there are eual 1 and 0 in that interval 
            // find the idx where the same sum was seen and take max
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }
            //if sum is not seen store it
            else mp[sum]=i;
        }

        return ans;
    }
};

int main() {
    return 0;
}
