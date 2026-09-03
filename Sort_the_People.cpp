/**
 * LeetCode Problem: Sort the People
 * Pushed by LeetCommit
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> a;
        for(int i=0;i<names.size();i++){
            a.push_back({heights[i],names[i]});
        }
        sort(a.rbegin(),a.rend());

        vector<string> s;
        for(auto &it:a){
            s.push_back(it.second);
        }
        return s;

    }
};

int main() {
    return 0;
}
