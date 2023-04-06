class Solution {
public:
    
    bool bfs(vector<vector<int>> &visited,int i,int j,vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        
        visited[i][j] = 1;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        bool res = true;
        
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,-1,0,1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newR = row + drow[i];
                int newC = col + dcol[i];
                
                if(!(newR >= 0 && newR < n && newC >= 0 && newC < m)) {
				    res = false;
			    }
                
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==0 && !visited[newR][newC]){
                    visited[newR][newC] = 1;
                    q.push({newR,newC});
                }
            }
        }
        
        return res;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(m<=2 || n<=2){
            return 0;
        }
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && grid[i][j] == 0 && bfs(visited,i,j,grid)){
                     count++;
                }
            }
        }
        
        return count;
    }
};