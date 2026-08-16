/**
 * LeetCode Problem: Minimize the Maximum Waiting Time at Synchronized Traffic Lights
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        vector<int> r=arrivalTime;
        for(int i=0;i<r.size();i++) r[i]%=period;

        int penalty=0;
        int maxLights=*max_element(lights.begin(),lights.end());
        
        for(int i=0;i<r.size();i++){
            if(r[i]<maxLights) continue;
            penalty=max(penalty,period-r[i]);
        }
        return penalty;

    }
};

int main() {
    return 0;
}
