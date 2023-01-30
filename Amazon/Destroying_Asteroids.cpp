#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int cnt=mass;
        sort(asteroids.begin(),asteroids.end());
        for (int i=0; i<asteroids.size(); i++){
            if (cnt>=asteroids[i]){
                cnt+=asteroids[i];
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};
