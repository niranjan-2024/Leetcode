class Solution {
public:
    
    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>>& grid){
        visited[row][col] = 1;
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int rowDelta=-1;rowDelta<=1;rowDelta++){
                for(int colDelta=-1;colDelta<=1;colDelta++){
                     if(rowDelta-colDelta==1 || colDelta-rowDelta==1){
                    int NeighbourRow = row + rowDelta;
                    int NeighbourCol = col + colDelta;
                    
                    if(NeighbourRow>=0 && NeighbourRow<n && NeighbourCol>=0 && NeighbourCol<m 
                    && grid[NeighbourRow][NeighbourCol]=='1' && !visited[NeighbourRow][NeighbourCol]){
                        visited[NeighbourRow][NeighbourCol] = 1;
                        q.push({NeighbourRow,NeighbourCol});
                     }
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        
        return count;
    }
};