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
    bool isCompleteTree(TreeNode* root) {
        bool nullBefore = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            auto node = q.front();
            q.pop();
            
            if(node == NULL){
                nullBefore = true;
            }
            else{
                if(nullBefore == true){
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};