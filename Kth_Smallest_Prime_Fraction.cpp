/**
 * LeetCode Problem: K-th Smallest Prime Fraction
 * Pushed by LeetCommit
 * Date: 2026-07-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        double low = 0.0, high = 1.0;

        while (true) {
            double mid = (low + high) / 2.0;

            int total = 0;

            int num = 0;
            int den = 1;

            int j = 1;

            for (int i = 0; i < n - 1; i++) {

                while (j < n && arr[i] > mid * arr[j])
                    j++;

                if (j == n)
                    break;

                total += (n - j);

                if (arr[i] * den > num * arr[j]) {
                    num = arr[i];
                    den = arr[j];
                }
            }

            if (total == k)
                return {num, den};

            if (total < k)
                low = mid;
            else
                high = mid;
        }
    }
};

int main() {
    return 0;
}
