#include<bits/stdc++.h>
using namesapce std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(), v.end());
        int st=0, en=v.size()-1;
        while(st<=v.size()-1 && v[st]==nums[st]){
            st++;
        }
        while(en>=0 && v[en]==nums[en]){
            en--;
        }
        //cout<<st<<" "<<en<<endl;
        if(en<0 || st>v.size()-1){return 0;}
        return en-st+1;
    }
};
