#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, string>m;
        unordered_map<string, int>m1;
        unordered_map<string, vector<int>>m2;
        for(int i=0; i<creators.size(); i++){
            m1[creators[i]]=views[i];
            m[creators[i]]=ids[i];
            m2[creators[i]].push_back(views[i]);
        }
        map<string, int>chk;
        
        for(auto it: m2){
            long long int sum=0;
            //cout<<it.first<<endl;
            for(auto it1: it.second){
                //cout<<it1<<" ";
                sum+=it1;
            }
            // cout<<" "<<sum<<endl;
            // cout<<endl;
            chk[it.first]=sum;
            //maxi=max(maxi, sum);
        }
        for(int i=0; i<creators.size(); i++){
            int num=m1[creators[i]];
            if(num<views[i]){
                
                m1[creators[i]]=views[i];
                m[creators[i]]=ids[i];
            }
            else if(num==views[i]){
                string x=min(ids[i], m[creators[i]]);
                m[creators[i]]=x;
            }
        }
        // for(auto it: m1){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // for(auto it: m){
        //     cout<<it.first<<" "<<it.second<<endl;;
        // }
        vector<vector<string>>ans;
        vector<pair<long long int, string>>v;
        for(auto it: chk){
            //cout<<maxi<<endl;
            //cout<<chk[it.first]<<" "<<it.first<<endl;
            //if(chk[it.first]==maxi){
                v.push_back({it.second, it.first});
            // }
        }
        sort(v.begin(), v.end());
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        // if(v.size()>1){
        //     if(v[0].first!=v[1].first){
        //         v.erase(v.begin());
        //     }
        // }
        reverse(v.begin(), v.end());
        long long int maxi=v[0].first;
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
        for(int i=0; i<v.size(); i++){
            if(maxi==v[i].first){
            vector<string>temp;
            temp.push_back(v[i].second);
            temp.push_back(m[v[i].second]);
            ans.push_back(temp);
            }
        }
        return ans;
    }
};
