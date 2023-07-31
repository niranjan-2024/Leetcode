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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int ans = 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            int minIndex = q.front().second;
            int firstIndex,lastIndex;
            
            for(int i=0;i<size;i++){
                long long int currIndex = q.front().second-minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0){
                    firstIndex = currIndex;
                }
                if(i == size-1){
                    lastIndex = currIndex;
                }
                
                if(node->left){
                    q.push({node->left,2*currIndex+1});
                }
                if(node->right){
                    q.push({node->right,2*currIndex+2});
                }
            }
            
            ans = max(ans,lastIndex-firstIndex+1);
        }
        
        return ans;
    }
};