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
    
    void inorder(TreeNode* root, vector<int> &a){
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> a;
        inorder(root, a);
        
        for(int i=1; i<a.size(); i++){
            if(a[i]<=a[i-1]) return false;
        }
        return true;
    }
};