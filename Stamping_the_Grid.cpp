/**
 * LeetCode Problem: Stamping the Grid
 * Pushed by LeetCommit
 * Date: 2026-07-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m=grid.size();
        int n=grid[0].size();
        int h=stampHeight;
        int w=stampWidth;
        
        vector<vector<int>> prefix(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=grid[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }   
        }

        vector<vector<int>> diff(m+2,vector<int>(n+2,0));

        for(int i=0;i+h<=m;i++){
            for(int j=0;j+w<=n;j++){

                int x1=i,y1=j;
                int x2=i+h-1,y2=j+w-1;

                int occupied=prefix[x2+1][y2+1]
                            -prefix[x1][y2+1]
                            -prefix[x2+1][y1]
                            +prefix[x1][y1];
                
                if(occupied==0){
                    diff[x1][y1]++;
                    diff[x2+1][y1]--;
                    diff[x1][y2+1]--;
                    diff[x2+1][y2+1]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];

                // Empty cell not covered
                if (grid[i][j] == 0 && diff[i][j] == 0)
                    return false;
            }
        }

        return true;
    }
};

//TLEeeeeeee-Brutforce

// class Solution {
// public:
//     bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int h=stampHeight;
//         int w=stampWidth;
//         int k=1;
//         for(int i=0;i<=m-h;i++){
//             for(int j=0;j<=n-w;j++){
//                   if(grid[i][j]==1) continue;
//                 bool isOk=true;

//                 for(int sr=i;sr<i+h;sr++){
//                     for(int sc=j;sc<j+w;sc++){
//                         if(grid[sr][sc]==1){
//                             isOk=false;
//                             break;
//                         }
//                     }
//                     if(isOk==false) break;
//                 }
//                     if(isOk){
//                         k++;
//                         for(int sr=i;sr<i+h;sr++){
//                             for(int sc=j;sc<j+w;sc++){
//                                 grid[sr][sc]=k;
//                             }
//                         } 
//                     }
//             }
//         }

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==0) return false;
//             }
//         }

//         return true;
//     }
// };

int main() {
    return 0;
}
