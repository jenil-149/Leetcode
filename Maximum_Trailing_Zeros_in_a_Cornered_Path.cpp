/**
 * LeetCode Problem: Maximum Trailing Zeros in a Cornered Path
 * Pushed by LeetCommit
 * Date: 2026-08-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int findFactors(int num,int div){
        int ans=0;
        while(num%div==0) {
            ans++;
            num/=div;
        }
        return ans;
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> two(n,vector<int>(m,0));
        vector<vector<int>> five(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                two[i][j]=findFactors(grid[i][j],2);
                five[i][j]=findFactors(grid[i][j],5);
            }
        }
        vector<vector<int>> rowTwo=two;
        vector<vector<int>> rowFive=five;

        vector<vector<int>> colTwo=two;
        vector<vector<int>> colFive=five;

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                rowTwo[i][j]+=rowTwo[i][j-1];
                rowFive[i][j]+=rowFive[i][j-1];  
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                colTwo[i][j]+=colTwo[i-1][j];
                colFive[i][j]+=colFive[i-1][j];
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //current i,j factors
                int f2=two[i][j];
                int f5=five[i][j];
                //curent row,col twos
                int rf2=rowTwo[i][m-1];
                int cf2=colTwo[n-1][j];
                //current row,col fives
                int rf5=rowFive[i][m-1];
                int cf5=colFive[n-1][j];

                //left+up (row till i col till j in both so current is counted 2 times ,subtract once)
                int total2=rowTwo[i][j]+colTwo[i][j]-f2;
                int total5=rowFive[i][j]+colFive[i][j]-f5;
                ans=max(ans,min(total2,total5));

                //left down
                total2=rowTwo[i][j]+ (cf2-colTwo[i][j]-f2)+f2;
                total5=rowFive[i][j]+(cf5-colFive[i][j]-f5)+f5;
                ans=max(ans,min(total2,total5));

                // right+up
                total2=colTwo[i][j]+ (rf2-rowTwo[i][j]-f2)+f2;
                total5=colFive[i][j]+(rf5-rowFive[i][j]-f5)+f5;
                ans=max(ans,min(total2,total5));
                
                // right+down
                total2=(cf2-colTwo[i][j]) + (rf2-rowTwo[i][j])+f2;
                total5=(cf5-colFive[i][j]) + (rf5-rowFive[i][j])+f5;
                ans=max(ans,min(total2,total5));

            }
        }

        return ans;

    }
};

int main() {
    return 0;
}
