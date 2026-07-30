/**
 * LeetCode Problem: Maximum Subarray Min-Product
 * Pushed by LeetCommit
 * Date: 2026-07-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;

    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<ll> prefix(n+1,0);
       
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+ nums[i];
        }

        vector<int> left(n),right(n);
        stack<int>st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }

        ll ans=0;
        for(int i=0;i<n;i++){

            ll sum=prefix[right[i]]-prefix[left[i]+1];
            ll product=sum*nums[i];
            ans=max(ans,product);
        }
        return ans%mod;

    }
};

int main() {
    return 0;
}
