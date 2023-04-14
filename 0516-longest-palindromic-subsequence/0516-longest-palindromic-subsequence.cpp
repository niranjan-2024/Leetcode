class Solution {
public:
    
    int solve(string &s,int left,int right,vector<vector<int>> &dp){
        if(left>right){
            return 0;
        }
        if(left==right){
            return 1;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s[left]==s[right]){
            dp[left][right] = 2+solve(s,left+1,right-1,dp);
        }
        else{
            dp[left][right] = max(solve(s,left+1,right,dp),solve(s,left,right-1,dp));
        }
        return dp[left][right];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};