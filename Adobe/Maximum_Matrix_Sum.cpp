#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int N=matrix.size() , negs=0 , mini=INT_MAX ;
        long long sum=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                sum+=abs(matrix[i][j]) ;
                mini=min(mini, abs(matrix[i][j])) ;
                if(matrix[i][j]<0){negs++;}
            }
        }
        if(negs%2==0){return sum;}
        return sum-2*mini;
    }
};
