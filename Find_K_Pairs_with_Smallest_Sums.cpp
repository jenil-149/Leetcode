/**
 * LeetCode Problem: Find K Pairs with Smallest Sums
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        int n=nums1.size();
        int m=nums2.size();
        if (n==0 || m==0) return ans;

        priority_queue<array<int,3>> pq;  // default max-heap

        for (int i = 0; i < min(n, k); i++)
            pq.push({-(nums1[i] + nums2[0]), i, 0});  // negate sum

        while (k-- && !pq.empty()) {
            auto [negSum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});
            if (j+1<m)
            pq.push({-(nums1[i] + nums2[j+1]), i, j+1});
        }

        return ans;
    }
};

int main() {
    return 0;
}
