/**
 * LeetCode Problem: Find All Groups of Farmland
 * Pushed by LeetCommit
 * Date: 2026-09-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n, m;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (land[i][j] == 1 && !vis[i][j]) {

                    int x1 = i;
                    int y1 = j;

                    int x2 = i;
                    int y2 = j;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty()) {

                        auto [x, y] = q.front();
                        q.pop();

                        // Update bottom-right corner
                        x2 = max(x2, x);
                        y2 = max(y2, y);

                        for (int k = 0; k < 4; k++) {

                            int nx = x + dr[k];
                            int ny = y + dc[k];

                            if (isValid(nx, ny) &&
                                land[nx][ny] == 1 &&
                                !vis[nx][ny]) {

                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }

                    ans.push_back({x1, y1, x2, y2});
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> vis;
    int n,m;

    bool isValid(int x,int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }

    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    void dfs(int x1,int y1,vector<vector<int>>& land,int &x2,int &y2){
        vis[x1][y1]=1;

        for(int i=0;i<4;i++){
            int nr=x1+dr[i];
            int nc=y1+dc[i];

            if(isValid(nr,nc) &&  land[nr][nc] && vis[nr][nc]!=1 ){
                x2=max(x2,nr);
                y2=max(y2,nc);
                dfs(nr,nc,land,x2,y2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();

        vis.assign(n,vector<int>(m,0));

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && vis[i][j]!=1){
                    int x1=i;
                    int y1=j;

                    int x2=i;
                    int y2=j;

                    dfs(x1,y1,land,x2,y2);

                    ans.push_back({x1,y1,x2,y2});
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
