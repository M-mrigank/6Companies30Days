#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findLength(vector<int>&nums1, vector<int>&nums2) {
        int ans=0;
        vector<int>dp(nums2.size()+1, 0);
        for(int i=0; i<nums1.size(); i++){
            for(int j=nums2.size()-1; j>=0; j--){
                if (nums1[i]==nums2[j]){
                    dp[j+1]=1+dp[j];
                } 
                else{
                    dp[j+1]=0;
                }           
                ans=max(ans, dp[j+1]);
            }
        }
        return ans;
    }
};
