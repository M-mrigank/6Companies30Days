#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0;
        int n=s.size();
        int m=words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<m;i++)
        {
            mp[words[i]]++;
        }
        for(auto i:mp)
        {
            string x=i.first;
            int p=0,q=0;
            while(p<n && q<x.size())
            {
                if(s[p]==x[q])
                {
                    p++;q++;
                }
                else 
                {
                    p++;
                }
            }
            if(q==x.size())
                count=count+i.second;
        }
        return count;
    }
};
