/**
 * LeetCode Problem: Pairs of Songs With Total Durations Divisible by 60
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
// can do simliar to two sum making a map and storing the remainder count
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60, 0);
        int ans = 0;

        for (int t : time) {
            int rem = t % 60;
            ans += freq[(60 - rem) % 60];
            freq[rem]++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
