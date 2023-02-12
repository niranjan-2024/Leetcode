class Solution {
public:
    
    long long ans;
    
    long long dfs(vector<vector<int>> &adj,int node,vector<bool> &visited,int seats){
        visited[node] = true;
        int representatives = 1;
        
        for(int i=0;i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(!visited[neighbour]){
                representatives += dfs(adj,neighbour,visited,seats);
            }
        }
        
        long long cars = representatives/seats;
        
        if(representatives%seats){
            cars++;
        }
        
        if(node != 0){
            ans += cars;
        }
        
        return representatives;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        ans = 0;
        
        if(n == 0){
            return 0;
        }
        
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<n;i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<bool> visited(n,false);
        
        dfs(adj,0,visited,seats);
        
        return ans;
    }
};