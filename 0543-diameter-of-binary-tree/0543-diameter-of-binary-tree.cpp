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
    
    int diameter = 0;
    
    int findDiameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftHeight = findDiameter(root->left);
        int rightHeight = findDiameter(root->right);
        
        diameter = max(diameter,leftHeight+rightHeight);
        
        return 1 + max(leftHeight,rightHeight); 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return diameter;
    }
};