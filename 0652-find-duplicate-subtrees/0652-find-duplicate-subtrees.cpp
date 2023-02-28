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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        dfs(root,m,ans);
        
        for(auto it:m){
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        return ans;
    }
    
    string dfs(TreeNode* root,unordered_map<string,int> &m,vector<TreeNode*> &ans){
        if(!root){
            return "";
        }
        
        string s = to_string(root->val) + " " + dfs(root->left,m,ans) + " " + dfs(root->right,m,ans);
        if(m[s]++ == 1){
            ans.push_back(root);
        }
        
        return s;
    }
};