/**
 * LeetCode Problem: Unique Paths
 * Pushed by LeetCommit
 * Date: 2026-07-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m,1);
        prev[0]=1;

        for(int i=1;i<n;i++){
            vector<int> curr(m,0);
            curr[0]=1;
            for(int j=1;j<m;j++){
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[m-1];
    }
};

int main() {
    return 0;
}
