/**
 * LeetCode Problem: Find Minimum Time to Reach Last Room I
 * Pushed by LeetCommit
 * Date: 2026-07-31
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dist(m,vector<int>(n,1e9));
        //{dist,{row,col}}
        priority_queue<pair<int,pair<int,int>>,
                            vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>
                            > pq;
        
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==m-1 && col==n-1) return d;

            if(d>dist[row][col]) continue;

            for(int i=0;i<4;i++){
                int r=row+dr[i];
                int c=col+dc[i];

                if(r<m && r>=0 && c>=0 && c<n){
                    int newDist=max(grid[r][c],d)+1;

                    if(newDist<dist[r][c]){
                        dist[r][c]=newDist;
                        pq.push({newDist,{r,c}});
                    }
                }
            }
        }

        return INT_MAX;
    }
};

int main() {
    return 0;
}
