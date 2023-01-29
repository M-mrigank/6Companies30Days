#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> us;
    int solve(int ind,string & s){
        if(ind>=s.size()) return 0;
        int maxi = 0;
        for(int i=ind;i<s.size();i++){
            string t = s.substr(ind,i-ind+1);
            if(us.find(t)==us.end())
            {
                us.insert(t);
                maxi = max(maxi,1+solve(i+1,s));
                us.erase(t);
            }
            
        }
        return maxi;
    }
    int maxUniqueSplit(string s) {
        return solve(0,s);
    }
};
