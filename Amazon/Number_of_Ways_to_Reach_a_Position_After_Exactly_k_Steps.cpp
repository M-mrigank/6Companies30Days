#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = (long long)(1e9+7);
    int dp[3001][1001];
    long long dfs(int s, int e, int k){
        if(s==e&&k==0)return 1;
        if(k==0)return 0;
        if(dp[s+1000][k]!=-1)return dp[s+1000][k];
        return dp[s+1000][k] = (dfs(s+1, e, k-1)+dfs(s-1, e, k-1))%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(startPos, endPos, k);
    }
};
