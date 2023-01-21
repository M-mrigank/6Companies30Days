#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) { 
        unordered_map<int,int>list;
        
        int i=0,j=0, count=0; 
        
        while(j<fruits.size()){
            list[fruits[j]]++;
            while(list.size()>2){
                list[fruits[i]]--;
                if(list[fruits[i]]==0)
                    list.erase(fruits[i]);
                i++;
            }
            if(list.size()<=2)
                count=max(count,j-i+1);
            j++;
        }
        return count;
    }
};
