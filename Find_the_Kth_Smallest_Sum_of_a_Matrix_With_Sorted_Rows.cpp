/**
 * LeetCode Problem: Find the Kth Smallest Sum of a Matrix With Sorted Rows
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();

        vector<int> sum=mat[0];
        if(sum.size()>k) sum.resize(k);
        //merge two rows at a time and keeping the size of k vector
        for(int i=1;i<m;i++){
            vector<int> next;

            for(int s:sum){
                for(int t:mat[i]){
                    next.push_back(s+t);
                }
            }

            sort(next.begin(),next.end());
            if(next.size()>k) next.resize(k);
            sum=next;
        }

        return sum[k-1];
        
    }
};

int main() {
    return 0;
}
