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

        int UPPER=x+11 ;
        vector<int> dist(UPPER+1,1e9);

        queue<int> q;
        q.push(x);
        dist[x]=0;

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            if(cur==y) return dist[cur];

            // cur - 1
            if (cur - 1 >= 1 && dist[cur - 1] == 1e9) {
                dist[cur - 1] = dist[cur] + 1;
                q.push(cur - 1);
            }

            if (cur + 1 <= UPPER && dist[cur + 1] == 1e9) {
                dist[cur + 1] = dist[cur] + 1;
                q.push(cur + 1);
            }


            if (cur % 5 == 0 && dist[cur / 5] == 1e9) {
                dist[cur / 5] = dist[cur] + 1;
                q.push(cur / 5);
            }

            if (cur % 11 == 0 && dist[cur / 11] == 1e9) {
                dist[cur / 11] = dist[cur] + 1;
                q.push(cur / 11);
            }

        }
        return dist[y];

    }
};

int main() {
    return 0;
}
