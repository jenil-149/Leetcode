/**
 * LeetCode Problem: Product of Array Except Self
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        vector<int> ans(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }

        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i]=pre[i]*suf[i];
        }

        return ans;
    }
};

int main() {
    return 0;
}
