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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> levelSum;
        
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
            
            levelSum.push_back(sum);
            q = temp;
        }
        
        sort(levelSum.begin(),levelSum.end());
        
        if(levelSum.size()<k){
            return -1;
        }
        
        return levelSum[levelSum.size()-k];
    }
};