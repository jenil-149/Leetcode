/**
 * LeetCode Problem: Make Lexicographically Smallest Array by Swapping Elements
 * Pushed by LeetCommit
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> vec=nums;
        sort(vec.begin(),vec.end());
        
        int grpNo=0;
        unordered_map<int,int> numToGrp;
        numToGrp[vec[0]]=grpNo;
        
        unordered_map<int,list<int>> grpToList;
        grpToList[grpNo].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                grpNo++;
            }
            numToGrp[vec[i]]=grpNo;
            grpToList[grpNo].push_back(vec[i]);
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int num=nums[i];
            int grp=numToGrp[num];

            ans[i]=*grpToList[grp].begin();
            grpToList[grp].pop_front();
        }

        return ans;

    }
};


int main() {
    return 0;
}
