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

    int rootSum(TreeNode* root,long long sum){
        if(root == NULL){
            return 0;
        }
        
        return ((sum == root->val) + rootSum(root->left,sum - root->val) + rootSum(root->right,sum - root->val));
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }

        return rootSum(root,targetSum) + pathSum(root->right,targetSum) + pathSum(root->left,targetSum);
    }
};