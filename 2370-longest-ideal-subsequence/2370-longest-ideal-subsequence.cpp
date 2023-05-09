class Solution {
public:
    
    int solve(string &s,int index,int prev,int k,vector<vector<int>> &dp){
        if(index >= s.length()){
            return 0;
        }
        if(dp[index][prev] != -1){
            return dp[index][prev];
        }
        
        int take = 0,notTake = 0;
        
        if(prev == 0 || abs(s[index]-prev) <= k){
            take = 1 + solve(s,index+1,s[index],k,dp);
        }
        notTake = solve(s,index+1,prev,k,dp);
        
        return dp[index][prev] = max(take,notTake);
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length()+1,vector<int>(150,-1));
        return solve(s,0,0,k,dp);
    }
};