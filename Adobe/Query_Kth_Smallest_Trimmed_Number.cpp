#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>v;
        for(auto it: queries){
            priority_queue<pair<string,int>>q;
            int trim=it[1];
            int k=it[0];
            for(int i=0; i<nums.size(); i++){
                string val=nums[i];
                if(trim<nums[i].size()){
                    val=nums[i].substr(nums[i].size()-trim,trim);
                }
                pair<string,int>val1={val,i};
                if(q.size()<k){
                    q.push(val1);
                }
                else{
                    if(val1<q.top()){
                        q.pop();
                        q.push(val1);
                    }
                }
            }
            v.push_back(q.top().second);
        }
        return v;
    }
};
