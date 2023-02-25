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
    
    void store(TreeNode* root,vector<int> &inorder){
        if(root == NULL){
            return;
        }
        
        store(root->left,inorder);
        inorder.push_back(root->val);
        store(root->right,inorder);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        store(root,inorder);
        int mini = INT_MAX;
        
        for(int i=1;i<inorder.size();i++){
            mini = min(mini,inorder[i]-inorder[i-1]);
        }
        
        return mini;
    }
};