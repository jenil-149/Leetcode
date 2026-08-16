/**
 * LeetCode Problem: Maximum Gap Between Stations
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int> left(n,-1),right(n,-1);

        int j=0;
        for(int i=0;i<n;i++){
            while(station[j]!=skill[i]){
                j++;
            }
            left[i]=j;
            j++;
        }
       
        j = m-1 ;
        for (int i= n-1;i>=0;i--) {

            while( skill[i] != station[j] ) j-- ;
            right[i] = j;
            j--;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,right[i+1]-left[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}
