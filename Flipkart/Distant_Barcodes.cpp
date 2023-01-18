#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()==1 || barcodes.size()==0){
            return barcodes;
        }
        map<int,int>m;
        vector<int>ans;
        for(auto it: barcodes){m[it]++;}
        priority_queue<pair<int,int>>q;
        for(auto it: m){q.push({it.second,it.first});}
        while(q.top().first>0){
            pair<int,int>p=q.top();
            q.pop();
            ans.push_back(p.second);
            p.first--;
            pair<int,int>p2=q.top();
            q.pop();
            if(p2.first>0){
                //cout<<p2.second<<endl;
                ans.push_back(p2.second);
                p2.first--;
            }
            q.push(p);
            q.push(p2);
        }
        return ans;
    }
};
