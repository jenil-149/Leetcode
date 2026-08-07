/**
 * LeetCode Problem: Is Graph Bipartite?
 * Pushed by LeetCommit
 * Date: 2026-08-07
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> colour(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(colour[i]) continue;
            q.push(i);
            colour[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int n:g[node]){
                    if(!colour[n]){
                        colour[n]=-colour[node];
                        q.push(n);
                    }
                    else if(colour[n]==colour[node]) return false;
                }
            } 
        }

        return true;
    }
};

int main() {
    return 0;
}
