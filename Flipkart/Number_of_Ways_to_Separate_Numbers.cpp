#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfCombinations(string num) {
        const int MOD =1e9+7; 
        int n = num.size(); 
        vector<vector<int>> lcs(n, vector<int>(n+1)); 
        for (int i=n-1; i>=0; --i){
            for (int j=n-1; j>i; --j){ 
                if (num[i]==num[j]){lcs[i][j]=1+lcs[i+1][j+1];}
            }
        }
        vector<vector<long>> memo(n, vector<long>(n+1, -1));
        function<long(int, int)>fn=[&](int lo, int hi){
            if(lo>=hi){return 0l;} 
            if(num[lo]=='0'){return 0l;} 
            if(lo==0){return 1l;}
            if (memo[lo][hi]==-1){
                long ans=fn(lo, hi-1); 
                if (0<=2*lo-hi){
                    int m=lcs[2*lo-hi][lo]; 
                    if(m>=hi-lo || num[2*lo-hi+m]<=num[lo+m]) 
                        ans=(ans+fn(2*lo-hi, lo))%MOD; 
                }
                if (0<=2*lo-hi+1) {
                    int m=lcs[2*lo-hi+1][lo]; 
                    if (m<hi-lo-1 && num[2*lo-hi+1+m]>num[lo+m])  
                        ans=(ans+fn(2*lo-hi+1, lo))%MOD; 
                }
                memo[lo][hi]=ans; 
            }
            return memo[lo][hi]; 
        };
        long ans=0; 
        for (int i=0; i<n; ++i){ans=(ans+fn(i, n))%MOD;}
        return ans; 
    }
};
