class Solution {
public:
    
    vector<int> directions = {0,1,0,-1,0};
    
    void fill(vector<vector<int>> &grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]){
            return;
        }
        
        grid[r][c] = 1;
        
        for(int i=0;i<4;i++){
            fill(grid,r+directions[i],c+directions[i+1]);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                    fill(grid,i,j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    ans++;
                    fill(grid,i,j);
                }
            }
        }
        
        return ans;
    }
};