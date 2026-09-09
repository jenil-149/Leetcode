/**
 * LeetCode Problem: Count Commas in Range II
 * Pushed by LeetCommit
 * Date: 2026-09-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll  ans=0;
        ll start=1000;

        while(start<=n){
            ans+=(n-start+1);
            start*=1000;
        }

        return ans;
    }
};



int main() {
    return 0;
}
