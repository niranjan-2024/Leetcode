class Solution {
public:
    
    int solve(int i,int k,vector<vector<int>>& piles,vector<vector<int>> &dp){
        if(dp[i][k] > 0){
            return dp[i][k];
        }
        
        if(i == piles.size() || k == 0){
            return 0;
        }
        
        int ans_with_exclude = solve(i+1,k,piles,dp);
        int include = 0;
        
        for(int j=0;j<piles[i].size() && j<k;j++){
            include += piles[i][j];
            ans_with_exclude = max(ans_with_exclude,solve(i+1,k-j-1,piles,dp)+include);
        }
        
        return dp[i][k] = ans_with_exclude;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        return solve(0,k,piles,dp);
    }
};