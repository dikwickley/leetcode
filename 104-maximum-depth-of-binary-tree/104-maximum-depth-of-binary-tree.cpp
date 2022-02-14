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
    
    int depth(TreeNode* r){
        if(r){
            return 1 + max(depth(r->right), depth(r->left));
        }
        return 0;
    }
    
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};