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

 TreeNode*solve(TreeNode* root, TreeNode* n1, TreeNode* n2){
        
        if(root==NULL){
            return NULL;
        }
        
        
        if(n1->val==root->val || n2->val==root->val){
            return root;
        }
        
        
        
        TreeNode*lefty=solve(root->left,n1,n2);
        TreeNode*righty=solve(root->right,n1,n2);;
        
        
        if(lefty!=NULL &&righty!=NULL){
            return root;
        }
        if(lefty!=NULL &&righty==NULL){
            return lefty;
        }
        else{
            return righty;
        }
    }


    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          return solve(root,p,q);

    }
};
