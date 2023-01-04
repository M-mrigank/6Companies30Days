#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int cnt=0;
        map<pair<int, int>, int>m;
        for(auto x:rectangles){
            m[{x[0], x[1]}]++; m[{x[2], x[3]}]++;
            m[{x[0], x[3]}]--; m[{x[2], x[1]}]--;
        }
        for(auto it: m){
            if(it.second!=0){
                if(abs(it.second)!=1){
                    return false;
                }
                cnt++;
            }
        }
        return (cnt==4);
    }
};
