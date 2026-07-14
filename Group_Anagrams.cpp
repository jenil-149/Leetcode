/**
 * LeetCode Problem: Group Anagrams
 * Pushed by LeetCommit
 * Date: 2026-07-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,string>> map;
        
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            map.push_back({s,strs[i]});
        }

        sort(map.begin(),map.end());

        vector<vector<string>> ans;
        vector<string> temp;
       

        for(int i=0;i<n;i++){
            vector<string> temp;
            temp.push_back(map[i].second);
            while(i<n-1 && map[i].first==map[i+1].first){
                temp.push_back(map[i+1].second);
                i++;
            }
            ans.push_back(temp);
        }  
        
        return ans;
    }
};

int main() {
    return 0;
}
