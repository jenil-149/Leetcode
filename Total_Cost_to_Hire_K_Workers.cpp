/**
 * LeetCode Problem: Total Cost to Hire K Workers
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int c=candidates;
        int n=costs.size();
        priority_queue<pair<int,int>,
                            vector<pair<int,int>>,
                            greater<pair<int,int>>
                            >pq;
        int l=0;
        int r=n-1;

        for(int i=0;i<c && l<=r;i++){
            pq.push({costs[l++],0});
            if(l<=r) pq.push({costs[r--],1});
        }
        while(k--){
            auto [cost,side]=pq.top();
            pq.pop();
            ans+=cost;
           if(l<=r){
                if(side==0){
                pq.push({costs[l++],0});
                }
                else{
                pq.push({costs[r--],1});
                }
           }
        }
    
        return ans;

    }
};

int main() {
    return 0;
}
