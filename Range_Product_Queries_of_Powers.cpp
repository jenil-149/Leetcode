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
    typedef long long ll;
    const int mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> powers;

        for (int k = 0; (1LL << k) <= n; k++) {
            if (n & (1LL << k)) {
                powers.push_back(k);
            }
        }

        vector<int> prefix(powers.size() + 1, 0);

        for (int i = 1; i <= powers.size(); i++) {
            prefix[i] = prefix[i - 1] + powers[i - 1];
        }

        vector<int> ans;
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];

            int p = prefix[r + 1] - prefix[l];
            ll a = 1;

            for (int i = 0; i < p; i++) {
                a = (a * 2) % mod;
            }

            ans.push_back((int)a);
        }

        return ans;
    }
};

int main() {
    return 0;
}
