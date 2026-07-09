/**
 * LeetCode Problem: Search a 2D Matrix
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=m*n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target){
                low=mid+1;

int main() {
    return 0;
}
