/**
 * LeetCode Problem: Maximum White Tiles Covered by a Carpet
 * Pushed by LeetCommit
 * Date: 2026-08-01
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;

    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();

        ll cover=0;
        int ans=0;
        int r=0;

        for(int l=0;l<n;l++){

            ll carpetEnd=1LL*tiles[l][0]+len-1;

            //fully coverd tiles
            while(r<n && tiles[r][1]<=carpetEnd){
                cover+=(tiles[r][1]-tiles[r][0]+1);
                r++;
            }
            //partial cover
            int partial=0;
            if(r<n && tiles[r][0]<=carpetEnd){
                partial=(carpetEnd-tiles[r][0]+1);
            }

            ans=max(ans,(int)cover+partial);

            //remove left interval
            cover-=(tiles[l][1]-tiles[l][0]+1);

        }
        return ans;


    }
};

int main() {
    return 0;
}
