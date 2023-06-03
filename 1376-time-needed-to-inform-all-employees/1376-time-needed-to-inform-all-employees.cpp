class Solution {
public:
    
    int dfs(vector<vector<int>> &graph,vector<int> &informTime,int node,int maxTime = 0){
        for(auto adjacentNode:graph[node]){
            maxTime = max(maxTime , dfs(graph,informTime,adjacentNode));
        }
        
        return maxTime + informTime[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        
        for(auto i=0;i<manager.size();i++){
            if(manager[i] != -1){
                graph[manager[i]].push_back(i);
            }
        }
        
        return dfs(graph,informTime,headID);
    }
};