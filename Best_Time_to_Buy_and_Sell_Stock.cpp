/**
 * LeetCode Problem: Best Time to Buy and Sell Stock
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int buyPrice=p[0];
        int profit=0;

        for(int i=1;i<p.size();i++){
            buyPrice=min(buyPrice,p[i]);
            profit=max(profit,p[i]-buyPrice);
        }
        
        return profit;
    }
};

int main() {
    return 0;
}
