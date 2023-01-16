#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>v(n, vector<int>(n, 1e9));
        int ans=-1, maxi=n;
        for(auto it: edges){
            v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];
        }
        for(int i=0; i<n; i++){v[i][i]=0;}
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(v[j][i]==1e9 || v[i][k]==1e9){continue;}
                    v[j][k]=min(v[j][k], v[j][i]+v[i][k]);
                }
            }
        }
        for(int i=0; i<n; i++){
            int cnt=0; 
            for(int j=0; j<n; j++){
                if(v[i][j]<=distanceThreshold){cnt++;}
            }
            if(maxi>=cnt){maxi=cnt; ans=i;}
        }
        return ans;
    }
};
