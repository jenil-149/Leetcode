/**
 * LeetCode Problem: Kth Smallest Amount With Single Denomination Combination
 * Pushed by LeetCommit
 * Date: 2026-08-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    using ll = long long;

    ll gcdll(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        sort(coins.begin(), coins.end());

        // Remove denominations that don't add anything new.
        vector<int> a;
        for (int x : coins) {
            bool ok = true;

            for (int y : a) {
                if (x % y == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                a.push_back(x);
        }

        int n = a.size();
        int N = 1 << n;

        vector<ll> L(N, 1);

        // Precompute LCM for every subset.
        for (int mask = 1; mask < N; ++mask) {
            int b = __builtin_ctz(mask);
            int prev = mask ^ (1 << b);

            ll g = gcdll(L[prev], a[b]);

            // We only care about values up to hi.
            L[mask] = L[prev] / g * a[b];
        }

        auto count = [&](ll x) {
            ll res = 0;

            for (int mask = 1; mask < N; ++mask) {
                if (L[mask] > x)
                    continue;

                ll cur = x / L[mask];

                if (__builtin_parity(mask))
                    res += cur;
                else
                    res -= cur;
            }

            return res;
        };

        ll lo = 1;
        ll hi = 1LL * a[0] * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    return 0;
}
