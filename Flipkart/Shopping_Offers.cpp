#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    map<pair<int,vector<int>>,int> mp;
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int offer){
        if(offer == special.size()){
            int temp = 0;
            for(int i=0;i<needs.size();i++){
                temp += (needs[i] * price[i]);
            }
            return temp;
        }
        if(mp.count({offer,needs})) return mp[{offer,needs}];
        int offerNotApplied = helper(price,special,needs,offer+1);

        int offerApplied = INT_MAX,n = special[offer].size();
        vector<int> temp = needs;
        bool isAllOk = true;
        for(int j=0;j<n-1;j++){
            temp[j] -= special[offer][j];
            if(temp[j] < 0){
                isAllOk = false;
                break;
            }
        }
        if(isAllOk){
            offerApplied = special[offer][n-1] + helper(price,special,temp,offer);
        }

        return mp[{offer,needs}] = min(offerApplied,offerNotApplied);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price,special,needs,0);
    }
};
