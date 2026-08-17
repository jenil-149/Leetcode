/**
 * LeetCode Problem: H-Index II
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        int l=0;
        int r=n-1;
        int ans=0;

        while(l<=r){

            int mid=l+(r-l)/2;
            if(c[mid]>=(n-mid)){
                ans=n-mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }

};


int main() {
    return 0;
}
