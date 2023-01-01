#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int>m;
        int cow=0, bull=0;
        for(int i=0; i<secret.size(); i++){
            m[secret[i]]++;
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]==guess[i]){
                bull++;
                //cout<<secret[i]<<" "<<m1[guess[i]]<<endl;
                m[guess[i]]--;
                if( m[guess[i]]==0){
                    m.erase(guess[i]);
                }
            }
            else{continue;}
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]!=guess[i]){
                if(m.find(guess[i])!=m.end()){
                    //cout<<guess[i]<<" "<<secret[i]<<" "<<m1[guess[i]]<<endl;
                    cow++;
                    m[guess[i]]--;
                    if( m[guess[i]]==0){
                        m.erase(guess[i]);
                    }
                }
            }
            else{continue;}
        }
        string ans="";
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cow);
        ans+='B';
        return ans;
    }
};
