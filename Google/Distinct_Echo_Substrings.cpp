#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.length();
        if(n==1){ 
            return 0;
        }
        if(n==2){
            if(text[0]==text[1]){ 
                return true;
            }
            return false;
        }
        set<string_view>s;
        string_view str=text;
        for(int i=0;i<n;i++){
           for(int len=2;i+len-1<n;len+=2){
               string_view a1=str.substr(i,len/2);
               string_view a2=str.substr(i+len/2,len/2);
               if(a1==a2){
                   s.insert(a1);
               }
           }
        }
        return s.size();
    }
};
