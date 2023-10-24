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
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> ans;
        int sz,maxi=INT_MIN;
        
        while(!q.empty()){
            sz = q.size();
            
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                
                maxi = max(maxi,node->val);
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            ans.push_back(maxi);
            maxi = INT_MIN;
        }
        
        return ans;
    }
};