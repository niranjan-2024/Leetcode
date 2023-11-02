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
    
    int ans = 0;
    
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        
        pair<int,int> left = solve(root->left);
        int left_sum = left.first;
        int left_count = left.second;
        
        pair<int,int> right = solve(root->right);
        int right_sum = right.first;
        int right_count = right.second;
        
        int sum = left_sum + right_sum + root->val;
        int count = left_count + right_count + 1;
        
        if((sum/count) == root->val){
            ans++;
        }
        
        return {sum,count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};