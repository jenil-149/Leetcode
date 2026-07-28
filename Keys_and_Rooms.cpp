/**
 * LeetCode Problem: Keys and Rooms
 * Pushed by LeetCommit
 * Date: 2026-07-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void dfs(int idx,vector<vector<int>>& rooms,vector<int> & vis){
        vis[idx]=1;
        for(auto adj:rooms[idx]){
            if(!vis[adj]){
                dfs(adj,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);

        for(auto v:vis){
            if(v==0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
