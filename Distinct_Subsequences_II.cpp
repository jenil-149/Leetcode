/**
 * LeetCode Problem: Distinct Subsequences II
 * Pushed by LeetCommit
 * Date: 2026-09-07
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    static const int mod = 1e9 + 7;
    using ll = long long;

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<ll> dp(n + 1, 0);
        vector<ll> last(26, 0);

        dp[0] = 1;  

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % mod;

            dp[i] = (dp[i] - last[c] + mod) % mod;

            last[c] = dp[i - 1];
        }

        return (dp[n] - 1 + mod) % mod;
    }
};

int main() {
    return 0;
}
