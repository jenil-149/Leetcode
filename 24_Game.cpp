/**
 * LeetCode Problem: 24 Game
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    double eps=0.1;

    bool solve(vector<double>& nums){
        if(nums.size()==1){
            return abs(nums[0]-24)<=eps;
        }

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;

                vector<double> temp;
                for(int k=0;k<nums.size();k++){
                    if(k!=i && k!=j) temp.push_back(nums[k]);
                } 
                double a=nums[i];
                double b=nums[j];

                vector<double> vals={a+b,a-b,b-a,a*b};
                if(abs(b)>0.0) vals.push_back(a/b);
                if(abs(a)>0.0) vals.push_back(b/a);

                for(auto val:vals){
                    temp.push_back(val);
                    if(solve(temp)==true) return true;
                    temp.pop_back();
                }

            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(auto it: cards){
            nums.push_back(1.0*it);
        }
        return solve(nums);
    }
};

int main() {
    return 0;
}
