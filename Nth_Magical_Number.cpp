/**
 * LeetCode Problem: Nth Magical Number
 * Pushed by LeetCommit
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low=min(a,b);
        long long high=1LL*n*low;

        long long LCM=lcm(a,b);
        const int mod=1e9+7;

        while(low<=high){
            long long mid=low+(high-low)/2;
            long long x=(mid/a)+(mid/b)-(mid/LCM);

            if(x>=n) high=mid-1;
            else low=mid+1;
        }
        return low%mod;

    }
};



int main() {
    return 0;
}
