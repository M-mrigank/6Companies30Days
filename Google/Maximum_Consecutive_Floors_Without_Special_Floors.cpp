#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& arr) {
        int res = 0,n =arr.size() ;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            if(i==0){
                res=max(res,arr[i]-bottom);
            }
            else{
                res=max(res,arr[i]-arr[i-1]-1);
            }
        }
        res=max(res,top-arr[n-1]);
        return res;
    }
};
