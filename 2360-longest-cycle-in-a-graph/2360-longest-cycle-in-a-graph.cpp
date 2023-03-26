class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int maxi = -1;
        
        vector<bool> visited(n,false);
        vector<int> dist_from_start(n,-1);
        
        function<void(int,int)> dfs = [&](int node,int currLen){
            if(!visited[node]){
                visited[node] = true;
                dist_from_start[node] = currLen;
                
                if(edges[node] != -1){
                    dfs(edges[node],currLen+1);
                }
                
                dist_from_start[node] = -1;
            }
            else{
                if(dist_from_start[node] != -1){
                    maxi = max(maxi,currLen-dist_from_start[node]);
                }
            }
        };
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,0);
            }
        }
        
        return maxi;
    }
};