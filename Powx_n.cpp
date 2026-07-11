/**
 * LeetCode Problem: Pow(x, n)
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1;

        double half = power(x, n / 2);
        double ans = half * half;
        if (n % 2) ans *= x;

        return ans;
    }

    double myPow(double x, int n) {

        long long N = n;
        
        if (N < 0) return 1.0 / power(x, -N);
        else return power(x, N);
    }
};

int main() {
    return 0;
}
