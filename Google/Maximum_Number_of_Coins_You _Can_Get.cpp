#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(),piles.end());
		int sum=0,n=piles.size();
        n/=3;
		for(int i=3*n-2; n--; i-=2){
            sum+=piles[i];
        }
		return sum;
	}
};
