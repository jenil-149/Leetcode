/**
 * LeetCode Problem: Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 * Pushed by LeetCommit
 * Date: 2026-07-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> prefix;
    int m,n;

    bool check(int len,int threshold){
        if(len==0) return true;

        for(int i=0;i+len<=m;i++){
            for(int j=0;j+len<=n;j++){

                int x1 = i;
                int y1 = j;
                int x2 = i + len - 1;
                int y2 = j + len - 1;

                int sum =
                    prefix[x2 + 1][y2 + 1]
                  - prefix[x1][y2 + 1]
                  - prefix[x2 + 1][y1]
                  + prefix[x1][y1];

                if (sum <= threshold)
                    return true;
            }
        }
        return false;

    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        m=mat.size();
        n=mat[0].size();

         prefix.assign(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=mat[i-1][j-1]
                            +prefix[i-1][j]
                            +prefix[i][j-1]
                            -prefix[i-1][j-1];
            }
        } 
        int low=0;
        int high=min(n,m);
        int ans=0;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(check(mid,threshold)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
};

int main() {
    return 0;
}
