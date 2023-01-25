#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(int n){
        int ans=0;
        while(n>0){
            int d=n%10;
            ans=(d*10)+ans;
            n=n/10;
        }
        if(ans==n){
            return true;
        }
        return false;
    }
    bool isStrictlyPalindromic(int n) {
        return palindrome(n);
    }
};
