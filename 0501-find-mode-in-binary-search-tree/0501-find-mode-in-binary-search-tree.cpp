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
    
    vector<int> ans;
    int currFreq = 1;
    int maxi = 1;
    int prev = INT_MIN;
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        inorder(root->left);
        
        if(root->val == prev){
            currFreq++;
        }
        else{
            currFreq = 1;
            prev = root->val;
        }
        
        if(currFreq == maxi){
            ans.push_back(root->val);
        }
        else if(currFreq > maxi){
            ans.clear();
            ans.push_back(root->val);
            maxi = currFreq;
        }
        
        inorder(root->right);
    }
};