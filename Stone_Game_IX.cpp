/**
 * LeetCode Problem: Stone Game IX
 * Pushed by LeetCommit
 * Date: 2026-08-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0=0,c1=0,c2=0;

        for(int s:stones){
            if(s%3==0) c0++;
            else if(s%3==1) c1++;
            else c2++;
        }
        if(c0%2==0) return c1>=1 && c2>=1;

        return abs(c1-c2)>2;


    }
};

int main() {
    return 0;
}
