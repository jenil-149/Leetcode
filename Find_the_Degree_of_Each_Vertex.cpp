/**
 * LeetCode Problem: Find the Degree of Each Vertex
 * Pushed by LeetCommit
 * Date: 2026-07-31
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> degree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                degree[i]+=matrix[i][j];
            }
        }
        return degree;
    }
};

int main() {
    return 0;
}
