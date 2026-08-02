/**
 * LeetCode Problem: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Pushed by LeetCommit
 * Date: 2026-08-02
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
   
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int reqSum=threshold*k;
        int sum=accumulate(arr.begin(),arr.begin()+k,0);
        int ans=0;
        if(sum>=reqSum) ans++;
        for(int i=k;i<n;i++){
            sum+=arr[i]-arr[i-k];
            if(sum>=reqSum) ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
