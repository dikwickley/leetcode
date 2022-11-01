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
class BSTIterator {
public:
    
    vector<int> inorder;
    int i = 0;
    
    void traverse(TreeNode* r){
        if(r==NULL) return;
        traverse(r->left);
        inorder.push_back(r->val);
        traverse(r->right);
        
    }
    
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        if(i>inorder.size()-1) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */