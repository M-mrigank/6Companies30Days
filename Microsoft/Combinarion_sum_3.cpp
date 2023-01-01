#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, int sum, vector<int>& v, vector<int>& v1, vector<vector<int>>& ans){
        if(sum==0){
            ans.push_back(v1);
        }
        for(int j=i; j<v.size(); j++){
            if(j>i && v[j]==v[j-1]){
                continue;
            }
            if(v[j]>sum){break;}
            v1.push_back(v[j]);
            f(j+1, sum-v[j], v, v1, ans);
            v1.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v={1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>>ans;
        vector<int>v1;
        f(0, n, v, v1, ans);
        for(int i=0; i<ans.size(); i++){
            if(ans[i].size()!=k){
                ans.erase(ans.begin()+i);
                if(ans.empty()){break;}
                i--;
            }
        }
        return ans;
    }
};