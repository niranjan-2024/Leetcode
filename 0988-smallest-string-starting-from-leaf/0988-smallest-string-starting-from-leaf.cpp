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
    string answer = "~";
    
    void traverse(TreeNode* root,string s){
            if (!root){
                return;
            }
            if (!root->left && !root->right){
                answer = min(answer,char(root->val+'a')+s);
            }
        
            traverse(root->left,char(root->val+'a')+s);
            traverse(root->right,char(root->val+'a')+s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        traverse(root,"");
        return answer;
    }
};