/**
 * LeetCode Problem: Range Sum Query - Mutable
 * Pushed by LeetCommit
 * Date: 2026-08-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class NumArray {
public:
    int n;
    vector<int> segTree;

    void buildSegmentTree(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }

        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,nums);
        buildSegmentTree(2*i+2,mid+1,r,nums);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        
    }

    void update(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx <= mid) {
            update(idx, val, 2*i+1, l, mid);
        }
        else {
            update(idx, val, 2*i+2, mid+1, r);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int left,int right,int i,int l,int r){

        if(l>right ||r<left) return 0;
        if(l>=left && r<=right) return segTree[i];

        int mid=(r-l)/2+l;
        return query(left,right,2*i+1,l,mid)+query(left,right,2*i+2,mid+1,r);
    }
     
    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n);
        buildSegmentTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    return 0;
}
