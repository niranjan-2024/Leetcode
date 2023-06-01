class Solution {
public:
    
    int mod = 1e9+7;
    int n,m,K;
    
    int dfs(int row,int col,int sum,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(row == n || col == m){
            return 0;
        }
        
        if(row == n-1 && col == m-1){
            return ((sum + grid[row][col])%K) == 0;
        }
        
        if(dp[row][col][sum] != -1){
            return dp[row][col][sum];
        }
        
        return dp[row][col][sum] = (dfs(row+1,col,(sum+grid[row][col])%K,grid,dp) + dfs(row,col+1,(sum+grid[row][col])%K,grid,dp))%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(K+1,-1)));
        
        return dfs(0,0,0,grid,dp);
    }
};