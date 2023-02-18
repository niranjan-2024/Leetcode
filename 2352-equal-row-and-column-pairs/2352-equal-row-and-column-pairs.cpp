class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> grid2(n,vector<int>(n,0));
        
        for (int i = 0; i < n; ++i){
          for (int j = 0; j < n; ++j) {
             grid2[j][i] = grid[i][j];
          }
        }
        
        int ans = 0;
        
        for(auto row:grid){
            for(auto col:grid2){
                if(row == col){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};