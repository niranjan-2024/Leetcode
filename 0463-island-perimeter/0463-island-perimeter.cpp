class Solution {
public:
    
    int ans , n, m;
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int row,int col){
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == 0){          
            ans += 1;
            return;
        }
        
        if(visited[row][col]){
            return;
        }
        
        visited[row][col] = 1;
        
        dfs(grid,visited,row+1,col);
        dfs(grid,visited,row-1,col);
        dfs(grid,visited,row,col+1);
        dfs(grid,visited,row,col-1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        ans = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(grid,visited,i,j);
                }
            }
        }
        
        return ans;
        
    }
};