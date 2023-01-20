#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts){
        if(n==0 || k==0){return 1.0;}
        queue<double>probs;
        double sumProb=0.0;
        for (int pts=maxPts; pts>=1; --pts){
            double prob=((k-1+pts)<=n)?1.0:0.0;
            sumProb += prob;
            probs.push(prob);
        }
        double lastProb=sumProb/maxPts;
        for (int currK=k-2; currK>=0; --currK){
            double oldProb = probs.front();
            sumProb+=lastProb-oldProb;
            probs.pop();
            probs.push(lastProb);
            lastProb=sumProb/maxPts;
        }
        return lastProb;
    }
};
