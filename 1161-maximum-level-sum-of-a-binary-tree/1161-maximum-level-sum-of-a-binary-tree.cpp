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
    
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1;
        long long levelSum = root->val;
        int ans = 1;
        q.push(root);
        
        while(!q.empty()){
            long long sum = 0;
            queue<TreeNode*> temp;
            
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto current = q.front();
                q.pop();
                
                sum += current->val;
                
                if(current->left){
                    temp.push(current->left);
                }
                if(current->right){
                    temp.push(current->right);
                }
            }
            
            if(sum>levelSum){
                levelSum = sum;
                ans = level;
            }
            
            level++;
            q = temp;
        }
        
        return ans;
    }
};