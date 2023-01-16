#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void remain(int k, int &x, int index, vector<int>v){
        if(v.size()==1){
            x=v[0];
            return;
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        remain(k, x, index, v);
        return;
    }
    
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        int index=0, x=-1;
        k--;
        remain(k, x, index, v);
        return x;
    }
};
