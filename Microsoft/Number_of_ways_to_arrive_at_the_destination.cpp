#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long int>>adj[n];
        long long int M=1e9+7;
        for(long long int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>>q;
        q.push({0, 0});
        vector<long long int>v(n, LONG_MAX), v1(n, 0);
        v[0]=0;
        v1[0]=1;
        while(!q.empty()){
            long long int tm=q.top().first, pos=q.top().second;
            q.pop();
            for(auto it: adj[pos]){
                if(tm+it[1]<v[it[0]]){
                    v[it[0]]=it[1]+tm;
                    v1[it[0]]=v1[pos];
                    q.push({v[it[0]], it[0]});
                }
                else if(tm+it[1]==v[it[0]]){
                    v1[it[0]]=(v1[it[0]]+v1[pos])%M;
                }
                
            }
        }
        //for(int i=0; i<n; i++){if(v[i]==1e9){return -1;}}
        //for(long long int i=0; i<n; i++){cout<<v1[i]<<" ";}cout<<endl;
        //if(v1[v1.size()-1]==0){return 1;}
        return v1[v1.size()-1]%M;
    }
};
