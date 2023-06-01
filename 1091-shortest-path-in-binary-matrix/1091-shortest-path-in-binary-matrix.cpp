class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,m-1};
        
        
        
        if(grid[0][0] != 0){
            return -1;
        }
        
        if(source.first==destination.first && source.second==destination.second){
            return 1;
        }
        
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        
        int dr[] = {-1,-1,0,1,1,1,0,-1};
        int dc[] = {0,1,1,1,0,-1,-1,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<8;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m 
                && grid[newr][newc] == 0 && distance + 1 < dist[newr][newc] ){
                    dist[newr][newc] = 1 + distance;
                    
                    if(newr == destination.first && newc == destination.second){
                        return distance + 1 + 1;
                    }
                    q.push({1 + distance,{newr,newc}});
                }
            }
        }
        
        return -1;
    }
};