/**
 * LeetCode Problem: Sum Game
 * Pushed by LeetCommit
 * Date: 2026-08-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();

        int leftSum=0;
        int rightSum=0;

        int leftQm=0;
        int rightQm=0;

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2) leftQm++;
                else rightQm++;
            }else{
                if(i<n/2) leftSum+=(num[i]-'0');
                else rightSum+=(num[i]-'0');
            }
        }
        if((leftQm+rightQm)%2==1) return true;
        
        int left= 2*leftSum + 9*leftQm;
        int right=2*rightSum+9*rightQm;

        return !(right==left);
    }

};

int main() {
    return 0;
}
