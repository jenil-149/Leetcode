/**
 * LeetCode Problem: Minimum Operations to Maximize Last Elements in Arrays
 * Pushed by LeetCommit
 * Date: 2026-08-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int operations1 = 0;
        int last1 = nums1[n - 1];
        int last2 = nums2[n - 1];

        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] > last1 || nums2[i] > last2) {
                if (nums2[i] <= last1 && nums1[i] <= last2) {
                    operations1++;
                } else {
                    operations1 = INT_MAX;
                    break;
                }
            }
        }

        int operations2 = 1;
        last1 = nums2[n - 1];
        last2 = nums1[n - 1];

        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] > last1 || nums2[i] > last2) {
                if (nums2[i] <= last1 && nums1[i] <= last2) {
                    operations2++;
                } else {
                    operations2 = INT_MAX;
                    break;
                }
            }
        }

        int ans = min(operations1, operations2);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}
