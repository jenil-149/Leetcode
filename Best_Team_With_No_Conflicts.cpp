/**
 * LeetCode Problem: Best Team With No Conflicts
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n=scores.size();
        vector<pair<int,int>> arr;
        vector<int> ans(n);
        int result=0;

        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            ans[i]=arr[i].second;

            for(int j=0;j<i;j++){
                if(arr[j].second<=arr[i].second){
                    ans[i]= max(ans[i],arr[i].second + ans[j]);
                }
            }
            result=max(result,ans[i]);
        }
        return result;
    }
};

int main() {
    return 0;
}
