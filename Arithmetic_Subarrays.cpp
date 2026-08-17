/**
 * LeetCode Problem: Arithmetic Subarrays
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();

        vector<bool> ans(m,true);

        for(int k=0;k<m;k++){
            int start=l[k];
            int end=r[k];
            
            vector<int> temp(nums.begin()+start,nums.begin()+end+1);
            sort(temp.begin(),temp.end());
            
            if(temp.size()<2){ 
                ans[k]=false;
                break;
            }

            int d=temp[1]-temp[0];
            for(int i=0;i<temp.size()-1;i++){
                if(temp[i+1]-temp[i]!=d){
                    ans[k]=false;
                    break;
                }
            }
        }
        return ans;

    }
};

int main() {
    return 0;
}
