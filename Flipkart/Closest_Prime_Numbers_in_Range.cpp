#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> nums;  
        vector<int> primes;
        for(int i=0; i<=right; i++){nums.push_back(true);}
        for(int i=2; i*i<=right; i++){
            if(nums[i]){
                for(int j=i*i; j<=right; j+=i){
                    nums[j]=false;
                }
            }
        }
        if(left==1){left++;}
        for(int i=left; i<=right; i++){
            if(nums[i]){primes.push_back(i);}
        }
        if(primes.size()<=1){return {-1, -1};}
        int num1=primes[0], num2=primes[1], d, diff=num2-num1;
        for(int i=0; i<primes.size()-1; i++){
            d=primes[i+1]-primes[i];
            if(diff>d){
                diff=d;
                num1=primes[i];
                num2=primes[i+1];
            }
        }
        return {num1, num2};
    }
};
