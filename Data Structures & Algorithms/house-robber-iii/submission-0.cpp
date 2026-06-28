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
    pair<int,int>solve(TreeNode* root, int &maxi){
        if(root==NULL){
            return {0,0};
        }
        pair<int, int>l=solve(root->left,maxi);
        pair<int,int>r=solve(root->right,maxi);
        int take=l.second+r.second+root->val;
        int not_take=max(l.first,l.second)+max(r.second,r.first);
        maxi=max(take,not_take);
        return{take,not_take};

    }
    int rob(TreeNode* root) {
        int maxi=0;
        pair<int,int>ans=solve(root, maxi);
        return maxi;
    }
};