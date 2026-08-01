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

        vector<ll> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+tiles[i][1]-tiles[i][0]+1;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            ll carpetEnd=1LL*tiles[i][0]+len-1;

            int high=n-1;
            int low=i;
            int idx=n;

            while(low<=high){
                int mid=low+(high-low)/2;

                if(tiles[mid][0]> carpetEnd){
                    idx=mid;
                    high=mid-1;

                }else{
                    low=mid+1;
                }
            }

            ll cover=prefix[idx]-prefix[i];
             if (idx > i) {
                cover -= max(0LL, 1LL * tiles[idx - 1][1] - carpetEnd);
            }

            ans = max(ans, (int)cover);
        }
        return ans;
    }
};

// class Solution {
// public:
//     typedef long long ll;

//     int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
//         sort(tiles.begin(),tiles.end());
//         int n=tiles.size();

//         ll cover=0;
//         int ans=0;
//         int r=0;

//         for(int l=0;l<n;l++){

//             ll carpetEnd=1LL*tiles[l][0]+len-1;

//             //fully coverd tiles
//             while(r<n && tiles[r][1]<=carpetEnd){
//                 cover+=(tiles[r][1]-tiles[r][0]+1);
//                 r++;
//             }
//             //partial cover
//             int partial=0;
//             if(r<n && tiles[r][0]<=carpetEnd){
//                 partial=(carpetEnd-tiles[r][0]+1);
//             }

//             ans=max(ans,(int)cover+partial);

//             //remove left interval
//             cover-=(tiles[l][1]-tiles[l][0]+1);

//         }
//         return ans;
//     }
// };

int main() {
    return 0;
}
