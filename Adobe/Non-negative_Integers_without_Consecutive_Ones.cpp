#include<bits/stdc++.h>
using namepsace std;

class Solution {
public:
    string s="";
    int dp[31][2][2];
    int find_min(int i,char last,int flag){
        if(i>=s.length()){
            return 1;
        }
        int ans;
        if(dp[i][last-'0'][flag]!=-1){
            return dp[i][last-'0'][flag];
        }        
        if(last=='0'){
            if(flag){
                ans=find_min(i+1,'1',flag)+find_min(i+1,'0',flag);
            }            
            else{
                if(s[i]=='1'){
                    ans=find_min(i+1,'1',flag)+find_min(i+1,'0',!flag);
                }
                else{
                    ans=find_min(i+1,'0', flag);
                }
            }
        }
        else
        {   
            if(s[i]=='1'){
                ans=flag==0? find_min(i+1,'0',!flag):find_min(i+1,'0',flag);
            }
            else{
                ans=find_min(i+1,'0',flag);
            }
        }
        return dp[i][last-'0'][flag]=ans;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        while(n){
            s.push_back(n%2+'0');
            n=n/2;
        }
        reverse(s.begin(), s.end());
        return find_min(0,'0',0);
    }
};

