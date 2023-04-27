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
    
    void inorder_traversal(TreeNode* root,set<int> &inorder){
        if(root == NULL){
            return;
        }
        
        inorder_traversal(root->left,inorder);
        inorder.insert(root->val);
        inorder_traversal(root->right,inorder);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> inorder;
        inorder_traversal(root,inorder);
        if (inorder.size() >= 2) {
            auto it = inorder.begin();
            ++it;  
            return *it;  
        } else {
            return -1;  
        }
    }
};