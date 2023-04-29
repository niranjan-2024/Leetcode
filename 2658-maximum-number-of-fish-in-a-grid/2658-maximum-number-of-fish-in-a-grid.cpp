class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        
        int ans = grid[r][c];
        grid[r][c] = 0;
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i) != abs(j)){
                    ans += dfs(grid,r+i,c+j);
                }
            }
        }
        
        return ans;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = max(ans,dfs(grid,i,j));
            }
        }
        
        return ans;
    }
};