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
int sum = 0;

    void inorder(TreeNode* root,int L,int H){
        if(root == NULL){
            return;
        }

        inorder(root->left,L,H);

        if(root->val >= L && root->val <= H){
            sum += root->val;
        }

        inorder(root->right,L,H);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root== NULL){
            return 0;
        }
        inorder(root,low,high);
        return sum;
    }
};