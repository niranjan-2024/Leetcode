class Solution {
public:
    
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int &detonated,int i){
        visited[i] = true;
        detonated++;
        
        for(int j=0;j<graph[i].size();j++){
            if(!visited[graph[i][j]]){
                dfs(graph,visited,detonated,graph[i][j]);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long rad = bombs[i][2];
            
            for(int j=0;j<n;j++){
                if(i != j){
                    long long x2 = bombs[j][0];
                    long long y2 = bombs[j][1];
                    
                    if((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <= rad*rad){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            int detonated = 0;
            vector<bool> visited(n,false);
            
            dfs(graph,visited,detonated,i);
            
            ans = max(ans,detonated);
        }
        
        return ans;
    }
};