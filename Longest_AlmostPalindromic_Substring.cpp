/**
 * LeetCode Problem: Longest Almost-Palindromic Substring
 * Pushed by LeetCommit
 * Date: 2026-08-02
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int almostPalindromic(string s) {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 1;

        for(int len = 2; len <= n; len++) {
            for(int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if(s[l] == s[r]) {
                    if(len == 2)  dp[l][r] = 0;
                    else dp[l][r] = dp[l + 1][r - 1];

                } else {
                    dp[l][r] = min(2, 1 + min(dp[l + 1][r], dp[l][r - 1]));
                }

                if(dp[l][r] <= 1)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
