/**
 * LeetCode Problem: Swim in Rising Water
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isValid(int r,int c,int n)  {return (r<n && r>=0 && c<n && c>=0);}

    int swimInWater(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<vector<int>> dist(n,vector<int>(n,1e9));
    // { currMax,r,c}
      priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>
            > pq;

        dist[0][0]=grid[0][0];

        int dr[4]={-1,0,1,0};
        int dc[4]={ 0,-1,0,1};
        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto [time, row, col] = pq.top();
            pq.pop();
            
            if(row==n-1 && col==n-1) return time;
            if(time>dist[row][col]) continue;

            for(int i=0;i<4;i++){
                int r=row+dr[i];
                int c=col+dc[i];

                if(isValid(r,c,n)){

                    int newTime=max(time,grid[r][c]);

                    if(newTime<dist[r][c]){
                    dist[r][c]=newTime;
                    pq.push({newTime,r,c});
                    }
                }
            }
        }
        return -1;

    }
};

int main() {
    return 0;
}
