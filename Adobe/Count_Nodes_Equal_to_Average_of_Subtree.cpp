#include<bits/stdc++.h>
using namepsace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int> solve(TreeNode* root){
        if(!root){return {0,0};}
        auto lh=solve(root->left);
        auto rh=solve(root->right);
        int sum=lh.first+rh.first+root->val;
        int n=lh.second+rh.second+1;
        if(sum/n==root->val){ans++;}
        return{sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
