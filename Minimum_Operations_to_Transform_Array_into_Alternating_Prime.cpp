/**
 * LeetCode Problem: Minimum Operations to Transform Array into Alternating Prime
 * Pushed by LeetCommit
 * Date: 2026-08-31
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    vector<int> getPrimes(int n, vector<bool>& isPrime) {
        isPrime.assign(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        return primes;
    }

    int minOperations(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime;
        vector<int> primes = getPrimes(mx + 100, isPrime);

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (i % 2 == 0) {
                // Need next prime >= x
                auto it = lower_bound(primes.begin(), primes.end(), x);
                ans += *it - x;
            }
            else {
                if (isPrime[x]) {
                    ans += (x == 2 ? 2 : 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
