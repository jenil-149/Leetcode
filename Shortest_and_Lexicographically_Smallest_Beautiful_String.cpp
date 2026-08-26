/**
 * LeetCode Problem: Shortest and Lexicographically Smallest Beautiful String
 * Pushed by LeetCommit
 * Date: 2026-08-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int l = 0;
        int ones = 0;
        int len = n + 1;

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1')
                    ones--;
                l++;
            }

            if (ones == k) {
                while (s[l] == '0')  l++;

                int currLen = r - l + 1;
                string curr = s.substr(l, currLen);

                if (currLen < len ||
                    (currLen == len && curr < ans)) {
                    len = currLen;
                    ans = curr;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
