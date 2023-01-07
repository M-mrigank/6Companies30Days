#include<bits/stdc++.h>
using namespace std;

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        while(root1){
            if(!root1->left){
                ans.push_back(root1->val);
                root1=root1->right;
            }
            else{
                TreeNode* r=root1->left;
                while(r->right && r->right!=root1){
                    r=r->right;
                }
                if(!r->right){
                    r->right=root1;
                    root1=root1->left;
                }
                else{
                    ans.push_back(root1->val);
                    r->right=NULL;
                    root1=root1->right;
                }
            }
        }
        while(root2){
            if(!root2->left){
                ans.push_back(root2->val);
                root2=root2->right;
            }
            else{
                TreeNode* r=root2->left;
                while(r->right && r->right!=root2){
                    r=r->right;
                }
                if(!r->right){
                    r->right=root2;
                    root2=root2->left;
                }
                else{
                    ans.push_back(root2->val);
                    r->right=NULL;
                    root2=root2->right;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
