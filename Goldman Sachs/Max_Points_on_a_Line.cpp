#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){return 1;}
        int ans=2;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int cnt=0;
                for(int k=0; k<points.size(); k++){
                    if(k!=i && k!=j && (points[i][1]-points[j][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[i][0]-points[j][0])){
                        cnt++;
                    }
                }
                ans=max(ans, cnt+2);
            }
        }
        return ans;
    }
};
