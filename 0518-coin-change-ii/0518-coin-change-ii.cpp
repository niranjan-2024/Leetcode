class Solution {
public:
    
    int coinChange(vector<int> &coins,int n,int amount,vector<vector<int>> &dp){
        if(n == 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        
        if(coins[n-1] > amount){
            return coinChange(coins,n-1,amount,dp);
        }
        
        int take = coinChange(coins,n,amount-coins[n-1],dp);
        int notTake = coinChange(coins,n-1,amount,dp);
        
        return dp[n][amount] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int n = coins.size();
        return coinChange(coins,n,amount,dp);
    }
};