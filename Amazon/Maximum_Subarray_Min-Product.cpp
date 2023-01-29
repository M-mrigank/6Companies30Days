#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmaller(vector<int>& nums){
        stack<int> st;
        int n=nums.size();
        vector<int> left(n,-1);
        for(int ind=0;ind<n;ind++){
            while(!st.empty() && nums[ind]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) left[ind]=st.top();
            st.push(ind);
        }
        return left;
    }
    vector<int> nextGreater(vector<int>& nums){
        stack<int> st;
        int n=nums.size();
        vector<int> right(n,n);
        for(int ind=n-1;ind>=0;ind--){
            while(!st.empty() && nums[ind]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) right[ind]=st.top();
            st.push(ind);
        }
        return right;
    }
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long> prefix;
        prefix.push_back(0);
        int n=nums.size();
        for(int ind=0;ind<n;ind++){
            prefix.push_back(prefix.back()+nums[ind]);
        }
        vector<int> left=nextSmaller(nums);
        vector<int> right=nextGreater(nums);
        long long ans=0,mod=1e9+7;
        for(int ind=0;ind<n;ind++){
            long long temp=(prefix[right[ind]] - prefix[left[ind] + 1]) * nums[ind];
            ans=max(ans,temp);
        }
        return ans%mod;
    }
};
