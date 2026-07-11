/**
 * LeetCode Problem: Divide Two Integers
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool isPositive = ((dividend < 0) == (divisor < 0));

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;
        // keep subtracting the largets powerof two from the dividend(instead of subtracting one by one)
        for (int i = 31; i >= 0; i--) {
            if ((b << i) <= a) {
                a -= (b << i);
                ans += (1LL << i);
            }
        }

        if (!isPositive)
        ans = -ans;

        return (int)ans;
    }
};

int main() {
    return 0;
}
