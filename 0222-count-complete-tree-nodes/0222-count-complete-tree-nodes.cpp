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
    void rec(TreeNode* r, int &count){
        
        if(r==NULL) return;
        
        rec(r->left, count);
        count++;
        rec(r->right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        rec(root, count);
        return count;
        
    }
};