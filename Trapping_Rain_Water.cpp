/**
 * LeetCode Problem: Trapping Rain Water
 * Pushed by LeetCommit
 * Date: 2026-07-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
// one approach is to make a prefix aary of maxL and suffix of maxR
// for each idx calculate min(maxL,maxR)-height[i];

// two pointer approach 
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int l=0;
        int r=n-1;
        int lMax=0;
        int rMax=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=lMax) lMax=height[l];
                else ans+=lMax-height[l];

                l++;
            }
            else {
                if(height[r]>=rMax) rMax=height[r];
                else ans+=rMax-height[r];

                r--;
            }
        }
     
        return ans;
    }
};

int main() {
    return 0;
}
