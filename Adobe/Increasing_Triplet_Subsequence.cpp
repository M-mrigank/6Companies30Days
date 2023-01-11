#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l=INT_MAX, l1=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(l>=nums[i]){l=nums[i];}
            else if(l1>=nums[i]){l1=nums[i];}
            else{return true;}
        }
        return false;
    }
};
