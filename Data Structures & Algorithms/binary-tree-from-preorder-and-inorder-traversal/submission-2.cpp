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
private :
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int InStart,int InEnd,int &PreStart,int PreEnd,  unordered_map<int,int>hashing){

        if(InStart>InEnd || PreStart>=PreEnd){
            return NULL;
        }

        int elm=preorder[PreStart++];
        TreeNode* root =new TreeNode(elm);
        int pos=hashing[elm];
        root->left=helper(preorder,inorder,InStart,pos-1,PreStart,PreEnd,hashing);
         root->right=helper(preorder,inorder,pos+1,InEnd,PreStart,PreEnd,hashing);
         return root;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>hashing;

        
        for(int i=0; i<inorder.size(); i++){
                hashing[inorder[i]]=i;
        }
        int InStart=0;
        int InEnd=inorder.size();
        int PreStart=0;
        int PreEnd=inorder.size();


            return helper(preorder,inorder,InStart,InEnd-1,PreStart,PreEnd,hashing);



    }
};
