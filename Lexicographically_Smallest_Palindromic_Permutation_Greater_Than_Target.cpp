/**
 * LeetCode Problem: Lexicographically Smallest Palindromic Permutation Greater Than Target
 * Pushed by LeetCommit
 * Date: 2026-08-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string build(string &half, char mid, bool odd) {
        string ans = half;
        if (odd) ans += mid;

        for (int i = (int)half.size() - 1; i >= 0; --i)
            ans += half[i];

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2;

        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        string half;
        vector<int> rem = halfCnt;

        for (int i = 0; i < m; i++) {
            for (int c = 0; c < 26; c++) {
                if (rem[c]) {
                    half += char('a' + c);
                    rem[c]--;
                    break;
                }
            }
        }

        string ans = build(half, mid, n & 1);
        if (ans > target) return ans;

        // Check if target's first half can be used as it is
        rem = halfCnt;
        bool ok = true;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (!rem[c]) {
                ok = false;
                break;
            }

            rem[c]--;
        }

        if (ok) {
            string h = target.substr(0, m);
            string candidate = build(h, mid, n & 1);

            if (candidate > target)
                return candidate;
        }

        // Make the first half just larger than target's first half
        for (int i = m - 1; i >= 0; i--) {
            rem = halfCnt;

            bool ok = true;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (!rem[c]) {
                    ok = false;
                    break;
                }

                rem[c]--;
            }

            if (!ok) continue;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (!rem[c]) continue;

                rem[c]--;

                string h = target.substr(0, i);
                h += char('a' + c);

                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        h += char('a' + x);
                        rem[x]--;
                    }
                }

                return build(h, mid, n & 1);
            }
        }

        return "";
    }
};


int main() {
    return 0;
}
