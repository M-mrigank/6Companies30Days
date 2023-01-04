#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>g(n);
        queue<pair<int, pair<int,int> > > q;
        int mx = INT_MIN, t=0, node=0;
        q.push({0,{0, 0}});
        set<int> nodes_in_path;
        vector<int> parent(n, -1), time(n), visited(n);
        queue<int> bq;
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        bq.push(bob);
        time[bob] = t;
        visited[bob] = 1;
        
        while(!bq.empty()) {
            auto node = bq.front(); bq.pop();
            for(int y : g[node]) {
                if(visited[y]) {
                    continue;
                }
                parent[y] = node;
                visited[y] = 1;
                time[y] = time[node]+1;
                bq.push(y);
            }
        }
        while(node != -1) {
            nodes_in_path.insert(node);
            node = parent[node];
        }
        for(int i = 0; i < n; i++) {
            if(nodes_in_path.find(i) == nodes_in_path.end()) {
                time[i] = -1;
            }
        }
        visited.assign(n, 0);
        
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            int x = node.first, current_time = node.second.first, val = node.second.second;
            if(visited[x]) {
                continue;
            }
            visited[x] = true;
            if(time[x] == -1) {
                val += amount[x];
            } else if(current_time == time[x]) {
                val += amount[x]/2;
            } else if(current_time < time[x]){
                val += amount[x];
            }
            if(g[x].size()==1 && x!=0){
                mx = max(mx, val);
            }
            for(int y : g[x]) {
                q.push({y, {current_time+1, val}});
            }
        }
        return mx;
    }
};
