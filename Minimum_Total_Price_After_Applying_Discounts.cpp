/**
 * LeetCode Problem: Minimum Total Price After Applying Discounts
 * Pushed by LeetCommit
 * Date: 2026-08-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        double ans=0.0;
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        int i=0;
        while(i<discounts.size() && i<prices.size()){
             double discountedPrice=(1.0*prices[i]*(100-discounts[i]))/100;
            ans+=discountedPrice;
            i++;
        }
        for(int j=i;j<prices.size();j++){
           ans+=1.0*prices[j];
        }

        return ans;
    }
};

int main() {
    return 0;
}
