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
    
    void preOrder(TreeNode*r, vector<int> &a){
        if(r){
            a.push_back(r->val);
            preOrder(r->left, a);
            preOrder(r->right, a);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        preOrder(root,res);
        
        return res;
    }
};