/**
 * LeetCode Problem: Longest Substring of One Repeating Character
 * Pushed by LeetCommit
 * Date: 2026-08-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    struct Node{
        int pre=0;
        int suf=0;
        int maxLen=0;
        int leftChar=0;
        int rightChar=0; 
    };

    int n;
    vector<Node> segmentTree;

    Node merge(Node &L, Node &R,int leftLen,int rightLen){
        Node result;

        result.leftChar=L.leftChar;
        result.rightChar=R.rightChar;
        result.pre=L.pre;
        result.suf=R.suf;

        if(L.pre==leftLen && L.rightChar==R.leftChar){
            result.pre=L.pre+R.pre;
        }

        if(R.suf==rightLen && L.rightChar==R.leftChar){
            result.suf=L.suf+R.suf;
        }

        result.maxLen=max(L.maxLen,R.maxLen);
        if(L.rightChar==R.leftChar){
            result.maxLen=max(result.maxLen,L.suf+R.pre);
        }

        return result;
    }

    void buildSegmentTree(int i,int l,int r,string &s){
        if(l==r){
            segmentTree[i]={ 1,1,1,s[l],s[r]};
            return;
        }

        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,s);
        buildSegmentTree(2*i+2,mid+1,r,s);

        segmentTree[i]=merge(segmentTree[2*i+1],segmentTree[2*i+2],mid-l+1,r-mid);
        
    }

    void update(int i,int l,int r,int pos,char ch){
        if(l==r){
            segmentTree[i]={1,1,1,ch,ch};   
            return;
        }
        int mid=l+(r-l)/2;

        if(pos<=mid){
            update(2*i+1,l,mid,pos,ch);
        }else{
            update(2*i+2,mid+1,r,pos,ch);
        }

        segmentTree[i]=merge(segmentTree[i*2+1],segmentTree[i*2+2],mid-l+1,r-mid);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        segmentTree.assign(4*n,Node());
        buildSegmentTree(0,0,n-1,s);

        int k=queryCharacters.size();
        vector<int> ans(k);

        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);

            ans[i]=segmentTree[0].maxLen;
        }
        return ans;
    }
};

int main() {
    return 0;
}
