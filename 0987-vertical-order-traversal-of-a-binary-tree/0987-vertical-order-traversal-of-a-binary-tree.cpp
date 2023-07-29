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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            TreeNode *node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            
            nodes[vertical][level].insert(node->val);
            
            if(node->left){
                q.push({node->left,{vertical-1,level+1}});
            }
            
            if(node->right){
                q.push({node->right,{vertical+1,level+1}});
            }
        }
        
        for(auto mp1 : nodes){
            vector<int> verticalOrder;
            for(auto mp2 : mp1.second){
                verticalOrder.insert(verticalOrder.end(),mp2.second.begin(),mp2.second.end());
            }
            ans.push_back(verticalOrder);
        }
        
        return ans;
    }
};