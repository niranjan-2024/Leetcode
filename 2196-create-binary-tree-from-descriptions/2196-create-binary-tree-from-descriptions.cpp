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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> parent_child;
        unordered_map<int,bool> isRoot;
        int rooti;
        
        for(auto nodes:descriptions){
            isRoot[nodes[0]] = isRoot[nodes[1]] = true;
        }
        
        for(auto &ele : descriptions){
            int cparent = ele[0];
            int cchild = ele[1];
            int isLeft = ele[2];
            
            isRoot[cchild] = false;
            
            auto parent = parent_child.count(cparent) ? parent_child[cparent] : (parent_child[cparent] = new TreeNode(cparent));
            auto child = parent_child.count(cchild) ? parent_child[cchild] : (parent_child[cchild] = new TreeNode(cchild));
            
            if(isLeft){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
        }
        
        for(auto root:isRoot){
            if(root.second){
                rooti = root.first;
            }
        }
        
        return parent_child[rooti];
    }
};