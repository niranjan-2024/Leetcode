class Solution {
public:
    
    bool dfs(int node,int col,int color[],vector<vector<int>>& graph){
        color[node] = col;
        
        for(auto next : graph[node]){
            if(color[next] == -1){
                if(dfs(next,!col,color,graph) == false){
                    return false;
                }
            }
            else if(color[next] == col){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++){
            color[i] = -1;
        }
        
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};