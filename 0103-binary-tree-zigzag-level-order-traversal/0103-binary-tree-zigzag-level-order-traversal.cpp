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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int LeftToRight = true;
        
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                
                int index = (LeftToRight) ? i : (size-i-1);
                temp[index] = node->val;
                
                if(node->left != NULL){
                    q.push(node->left);
                }
                
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            
            ans.push_back(temp);
            LeftToRight = !LeftToRight;
        }
        
        return ans;
    }
};