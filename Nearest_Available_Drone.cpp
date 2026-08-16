/**
 * LeetCode Problem: Nearest Available Drone
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int nearestDrone(vector<vector<int>>& d, vector<int>& t) {
        int idx=-1;
        int dist=INT_MAX;
        for(int i=0;i<d.size();i++ ){
            int m=abs(d[i][0]-t[0])+abs(d[i][1]-t[1]);

            if(m<=d[i][2] && m<dist){
                dist=m;
                idx=i;
            }
        }
        return idx;

    }
};

int main() {
    return 0;
}
