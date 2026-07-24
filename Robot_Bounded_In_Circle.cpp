/**
 * LeetCode Problem: Robot Bounded In Circle
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isRobotBounded(string instructions) {
        unordered_map<char,int> mp;

        char currDirection='N';
        
        for(char i:instructions){
            if(i=='G') mp[currDirection]++;
            else{
                if(currDirection=='N')
                    currDirection=(i=='L'?'W':'E');
                else if(currDirection=='S')
                    currDirection=(i=='L'?'E':'W');
                else if(currDirection=='E')
                    currDirection=(i=='L'?'N':'S');
                else if(currDirection=='W')
                    currDirection=(i=='L'?'S':'N');
            }
        }

        //check if it is at origin or not facing north(it will result into circle)
        if((mp['N'] == mp['S'] && mp['W'] == mp['E']) || currDirection != 'N'){
            return true;
        }

        return false;
    }
};

int main() {
    return 0;
}
