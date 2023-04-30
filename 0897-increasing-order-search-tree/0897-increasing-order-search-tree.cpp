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
    
    void storeInorder(TreeNode* root,vector<int> &inorder){
        if(root == NULL){
            return;
        }
        
        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        
        vector<int> inorder;
        storeInorder(root,inorder);
        
        TreeNode* newRoot = new TreeNode(inorder[0]);
        TreeNode* curr = newRoot;
        
        for(int i=1;i<inorder.size();i++){
            TreeNode* now = new TreeNode(inorder[i]);
            curr->right = now;
            curr = now;
        }
        
        return newRoot;
    }
};