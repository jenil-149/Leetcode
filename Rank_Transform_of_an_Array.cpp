/**
 * LeetCode Problem: Rank Transform of an Array
 * Pushed by LeetCommit
 * Date: 2026-07-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();

        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> numToRank;
        int rank=1;
        
        for(auto it: temp){
            //assign rank if num is not present in the hashmap 
            if(numToRank.find(it)==numToRank.end()){
                numToRank[it]=rank;
                rank++;
            }
        }
        // for each num replace them with their rank
        for(int i=0;i<n;i++){
            arr[i]=numToRank[arr[i]];
        }
        return arr;

    }
};

int main() {
    return 0;
}
