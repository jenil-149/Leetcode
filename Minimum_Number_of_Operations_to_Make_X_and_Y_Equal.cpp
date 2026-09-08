/**
 * LeetCode Problem: Minimum Number of Operations to Make X and Y Equal
 * Pushed by LeetCommit
 * Date: 2026-09-08
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) return y-x;

        int mx=1e4+10;
        vector<int> dist(mx,1e9);

        queue<int> q;
        q.push(x);
        dist[x]=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            if(curr==y) return dist[curr];

            vector<int> next;
            if(curr%11==0) next.push_back(curr/11);
            if(curr%5==0) next.push_back(curr/5);

            next.push_back(curr-1);

            if(curr+1<=mx) next.push_back(curr+1);

            for(int n:next){
                if(n>=1  && n<=mx && dist[n]==1e9){
                    dist[n]=dist[curr]+1;
                    q.push(n);
                }
            }

        }
        return dist[y];

    }
};

int main() {
    return 0;
}
