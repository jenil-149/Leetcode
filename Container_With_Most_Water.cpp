/**
 * LeetCode Problem: Container With Most Water
 * Pushed by LeetCommit
 * Date: 2026-07-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;

        int l=0,r=height.size()-1;
        while(l<=r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
