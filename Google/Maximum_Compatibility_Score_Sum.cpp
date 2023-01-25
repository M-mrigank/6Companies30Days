#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>visited;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        int m = students[0].size();
        visited.resize(n+1, 0);
        return permutation(students, mentors, 0, n, m);
    }
    int permutation(vector<vector<int>>& students, vector<vector<int>>& mentors, int pos, int n, int m) {
        if(pos>=n) {
            return 0;
        }
        int mx = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int cnt = 0;
                for(int j = 0; j < m; j++) {
                    if(students[pos][j] == mentors[i][j]) cnt++;
                }
                visited[i] = 1;
                mx = max(mx, cnt+permutation(students, mentors, pos+1, n, m));
                visited[i] = 0;
            }
        }
        return mx;
    }
};
