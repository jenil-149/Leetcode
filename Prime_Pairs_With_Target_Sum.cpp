/**
 * LeetCode Problem: Prime Pairs With Target Sum
 * Pushed by LeetCommit
 * Date: 2026-09-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void getPrimes(int n, vector<bool>& p) {
        p[0] = false;
        p[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (p[i]) {
                for (int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> p(n+1,true);
        getPrimes(n,p);

        vector<vector<int>> ans;

        for(int i=2;i<=n/2;i++){
            if(p[i] && p[n-i]){
                ans.push_back({i,n-i});
            }
        }

        return ans;

    }
};

int main() {
    return 0;
}
