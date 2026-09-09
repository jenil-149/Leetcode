/**
 * LeetCode Problem: Range Product Queries of Powers
 * Pushed by LeetCommit
 * Date: 2026-09-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    using ll = long long;

    const ll MOD = 1e9 + 7;

    ll binpow(ll base, int exp) {
        ll ans = 1;

        while (exp > 0) {
            if (exp & 1)
                ans = ans * base % MOD;

            base = base * base % MOD;
            exp >>= 1;
        }

        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        // Store exponents of set bits
        vector<int> powers;

        for (int k = 0; (1LL << k) <= n; k++) {
            if (n & (1LL << k))
                powers.push_back(k);
        }

        // Prefix sum of exponents
        vector<int> prefix(powers.size() + 1, 0);

        for (int i = 0; i < powers.size(); i++) {
            prefix[i + 1] = prefix[i] + powers[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // Sum of powers from l to r
            int exponent = prefix[r + 1] - prefix[l];

            ans.push_back(binpow(2, exponent));
        }

        return ans;
    }
};

int main() {
    return 0;
}
