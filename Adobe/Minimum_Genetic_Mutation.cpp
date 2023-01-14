#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=-1;
    void solve(string &start, string &end, string s, vector<string> &bank, int i, int n, int length){
        if(s==end){
            if(ans!=-1)        {
                ans=min(ans,length);
            }
            else        {
                ans=length;
            }
            return;
        }
        if(i==n){
            return;
        }
        for(int itr=i; itr<n; itr++){
            string t=bank[itr];
            int diff=0;
            for(int j=0; j<8; j++){
                if(t[j]!=s[j]){
                    diff++;
                }
            }
            if(diff==1){
                solve(start,end,t,bank,i+1,n,length+1);
            }
        }
        return;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int n=bank.size();
        solve(start, end, start, bank, 0, n, 0);
        return ans;
        
        
    }
};
