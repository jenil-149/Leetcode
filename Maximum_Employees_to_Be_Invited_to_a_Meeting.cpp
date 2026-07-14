/**
 * LeetCode Problem: Maximum Employees to Be Invited to a Meeting
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++) indegree[favorite[i]]++;

        vector<int> depth(n,1);
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            int nxt=favorite[node];
            depth[nxt]=max(depth[nxt],depth[node]+1);
            indegree[nxt]--;

            if(indegree[nxt] == 0)  q.push(nxt);

        }

        int longestCycle=0;
        int twoCycleSum=0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){

            if(indegree[i]>0 && !vis[i]){
                int curr=i;
                int len=0;

                while(!vis[curr]){
                    vis[curr] = 1;
                    len++;
                    curr = favorite[curr];
                }

                if(len == 2){
                    int a = i;
                    int b = favorite[i];

                    twoCycleSum += depth[a] + depth[b];
                }else{
                    longestCycle = max(longestCycle, len);
                }
            }
        }
        return max(longestCycle, twoCycleSum);
    }
};

int main() {
    return 0;
}
