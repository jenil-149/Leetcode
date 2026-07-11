/**
 * LeetCode Problem: Rotate Image
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //take adjoin 
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //revsese each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
       
    }
};

int main() {
    return 0;
}
