/**
 * LeetCode Problem: Find Champion II
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);
        for(auto e:edges){
            indegree[e[1]]++;
        }
        int cnt=0;
        int ans=-1;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                ans=i;
            }
        }
        return cnt==1?ans:-1;
    }
};

int main() {
    return 0;
}
