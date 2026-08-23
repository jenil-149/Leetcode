/**
 * LeetCode Problem: Valid K-Unique Subarrays I
 * Pushed by LeetCommit
 * Date: 2026-08-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> freq;
    int distinct=0;
    int odd=0;

    void add(int x){
        freq[x]++;
        
        if(freq[x]==1) distinct++;
        if(freq[x]%2==1) odd++;
        else odd--;
    }
    void remove(int x){
        freq[x]--;

        if(freq[x]==0) distinct--;
        if(freq[x]%2==1) odd++;
        else odd--;
    }
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();

        vector<bool> ans(m);

        int mx=*max_element(nums.begin(),nums.end());
        freq.assign(mx+1,0);

        vector<int> order(m);

        for (int i = 0; i < m; i++)
            order[i] = i;

        int block = max(1, (int)sqrt(n));

        sort(order.begin(), order.end(),
            [&](int a, int b)
            {
                int blockA = queries[a][0] / block;
                int blockB = queries[b][0] / block;

                if (blockA != blockB)
                    return blockA < blockB;

                return queries[a][1] < queries[b][1];
            });
        
        int L=0;
        int R=-1;

        for(int id:order){

            int l=queries[id][0];
            int r=queries[id][1];

            while(R<r){
                R++;
                add(nums[R]);
            }
            while(L>l){
                L--;
                add(nums[L]);
            }

            while(R>r){
                remove(nums[R]);
                R--;
            }
            while(L<l){
                remove(nums[L]);
                L++;
            }

            ans[id]=(distinct==k && odd==0);

        }

        return ans;

    }
};

int main() {
    return 0;
}
