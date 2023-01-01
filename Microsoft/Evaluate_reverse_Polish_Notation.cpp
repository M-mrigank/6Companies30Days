#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]!="+" && tokens[i]!="/" && tokens[i]!="*" && tokens[i]!="-"){
                long long int num=0, chk=1;
                for(int j=0; j<tokens[i].size(); j++){
                    if(tokens[i][j]=='-'){chk=-1; continue;}
                    num+=(tokens[i][j]-'0');
                    num*=10;
                }
                num/=10;
                if(chk==-1){num*=(-1);}
                //cout<<num<<endl;
                s.push(num);
            }
            else if(tokens[i]=="+"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                //cout<<t1<<" "<<t2<<endl;
                s.push(t1+t2);
            }
            else if(tokens[i]=="-"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                //cout<<t1<<" "<<t2<<endl;
                s.pop();
                s.push(t2-t1);
            }
            else if(tokens[i]=="*"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                //cout<<t1<<" "<<t2<<endl;
                s.push(t1*t2);
            }
            else if(tokens[i]=="/"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                //cout<<t1<<" "<<t2<<endl;
                s.push(t2/t1);
            }
        }
        return s.top();
    }
};