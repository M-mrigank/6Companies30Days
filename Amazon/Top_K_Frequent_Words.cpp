#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct lambda {
        bool operator()(pair<string, int>& a, pair<string, int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        //fi(it, m){cout<<it.first<<" "<<it.second<<endl;}
        vector<string>v;
        priority_queue<pair<string, int>, vector<pair<string, int>>, lambda>mnhp;
        for(auto it: m){
            mnhp.push({it.first, it.second});
            //cout<<it.second<<" "<<it.first<<endl;
            while(mnhp.size()>k){
                //cout<<mxhp.top().first<<" "<<mxhp.top().second<<endl;
                mnhp.pop();
            }
        }
        vector<int>v1;
        int pos=0;
        while(!mnhp.empty()){
            //cout<<mnhp.top().first<<" "<<mnhp.top().second<<endl;
            string s=mnhp.top().first;
            v.push_back(s);
            mnhp.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
