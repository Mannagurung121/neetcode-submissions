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
      bool find(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (q->val != p->val) {
            return false;
        }
        bool l = find(p->left, q->left);
        bool r = find(p->right, q->right);
        return l & r;
    }
    bool solve(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (subRoot != NULL && front != NULL &&
                subRoot->val == front->val) {
                if (find(front, subRoot)) {
                    return true;
                }
            }
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root ==NULL ||subRoot==NULL){
            return false;
        }
        return solve(root, subRoot);
    }
};
