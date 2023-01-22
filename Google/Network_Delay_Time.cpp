#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj[n];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        vector<int>v(n, 1e9);
        queue<pair<int, int>>q;
        q.push({k-1, 0});
        v[k-1]=0;
        while(!q.empty()){
            int pos=q.front().first, wt=q.front().second;
            q.pop();
            for(auto it: adj[pos]){
                if(wt+it[1]<v[it[0]]){
                    v[it[0]]=it[1]+wt;
                    q.push({it[0], v[it[0]]});
                }
            }
        }
        //for(int i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;
        for(int i=0; i<v.size(); i++){if(v[i]==1e9){return -1;}}
        return *max_element(v.begin(), v.end());
    }
};
