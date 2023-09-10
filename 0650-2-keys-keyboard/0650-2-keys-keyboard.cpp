class Solution {
public:
    
    int solve(int steps,int value,int copy,int &n,vector<vector<int>> &dp){
        if(steps>n || value>n){
            return INT_MAX;
        }
        
        if(value == n){
            return steps;
        }
        
        if(dp[steps][value] != -1){
            return dp[steps][value];
        }
        
        return dp[steps][value] = min(solve(steps+1,value+copy,copy,n,dp),solve(steps+2,value+value,value,n,dp));
    }
    
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(1,1,1,n,dp);
    }
};