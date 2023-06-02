class Solution {
public:
    
    int bfs(vector<vector<int>> &grid,int row,int col){
        int area = 1;
        
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 0;
                    area++;
                    q.push({newRow,newCol});
                }
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area,bfs(grid,i,j));
                }
            }
        }
        
        return max_area;
    }
};