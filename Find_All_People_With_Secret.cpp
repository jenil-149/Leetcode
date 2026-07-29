/**
 * LeetCode Problem: Find All People With Secret
 * Pushed by LeetCommit
 * Date: 2026-07-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        //adj[u]={time,v}
        vector<pair<int,int>> adj[n];
        for(auto m:meetings){
            int u=m[0];
            int v=m[1];
            int time=m[2];

            adj[u].push_back({time,v});
            adj[v].push_back({time,u});
        }
        vector<int> earliest(n, INT_MAX);

        earliest[0] = 0;
        earliest[firstPerson] = 0;

        priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

        pq.push({0,0});
        pq.push({0,firstPerson});

        while(!pq.empty()){

            auto [time,node] = pq.top();
            pq.pop();

            if(time > earliest[node]) continue;

            for(auto [meet,v] : adj[node]){

                if(meet >= time && meet < earliest[v]){
                    earliest[v] = meet;
                    pq.push({meet,v});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(earliest[i]!=INT_MAX) ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    return 0;
}
