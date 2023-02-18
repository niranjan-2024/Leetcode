class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }
        
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            ans.clear();
            int size = q.size();
            
            for(int i=0;i<size;i++){
                int current = q.front();
                q.pop();
                ans.push_back(current);
                
                for(auto adjacent:adj[current]){
                    degree[adjacent]--;
                    if(degree[adjacent] == 1){
                        q.push(adjacent);
                    }
                }
            }
        }
        
        return ans;
    }
};