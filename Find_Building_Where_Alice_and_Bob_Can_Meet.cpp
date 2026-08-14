/**
 * LeetCode Problem: Find Building Where Alice and Bob Can Meet
 * Pushed by LeetCommit
 * Date: 2026-08-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    void buildST(int i, int l, int r, int segmentTree[],
                 vector<int>& heights) {

        if(l == r) {
            segmentTree[i] = l;
            return;
        }

        int mid = l + (r-l)/2;

        buildST(2*i+1, l, mid, segmentTree, heights);
        buildST(2*i+2, mid+1, r, segmentTree, heights);

        int lIdx = segmentTree[2*i+1];
        int rIdx = segmentTree[2*i+2];

        if(heights[lIdx] >= heights[rIdx])
            segmentTree[i] = lIdx;
        else
            segmentTree[i] = rIdx;
    }

    int* constructST(vector<int>& heights, int n) {

        int* segmentTree = new int[4*n];

        buildST(0, 0, n-1, segmentTree, heights);

        return segmentTree;
    }

    int findFirst(int i, int l, int r, int start, int value,
                  int st[], vector<int>& heights) {

        // Completely before start
        // OR maximum in this segment isn't enough
        if(r < start || heights[st[i]] <= value)
            return -1;

        // We know this position works
        if(l == r)
            return l;

        int mid = l + (r-l)/2;

        // Search left first
        int left = findFirst(2*i+1, l, mid, start,
                             value, st, heights);

        if(left != -1)
            return left;

        // Then search right
        return findFirst(2*i+2, mid+1, r, start,
                         value, st, heights);
    }

    vector<int> leftmostBuildingQueries(
        vector<int>& heights,
        vector<vector<int>>& queries) {

        int n = heights.size();

        int* segmentTree = constructST(heights, n);

        vector<int> ans;

        for(auto &q : queries) {

            int a = min(q[0], q[1]);
            int b = max(q[0], q[1]);

            // Same building
            if(a == b) {
                ans.push_back(a);
                continue;
            }

            // Bob can directly move to b
            if(heights[b] > heights[a]) {
                ans.push_back(b);
                continue;
            }

            int value = max(heights[a], heights[b]);

            int idx = findFirst(
                0, 0, n-1,
                b+1,
                value,
                segmentTree,
                heights
            );

            ans.push_back(idx);
        }

        delete[] segmentTree;

        return ans;
    }
};

int main() {
    return 0;
}
