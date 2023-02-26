class Solution {
public:
    
    int solve(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(word1[i] == word2[j]){
            dp[i][j] = solve(word1,word2,i-1,j-1,dp);
        }
        else{
            dp[i][j] = 1 + min(solve(word1,word2,i-1,j-1,dp),min(solve(word1,word2,i,j-1,dp),solve(word1,word2,i-1,j,dp)));
        }
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        int i = word1.size()-1;
        int j = word2.size()-1;
        
        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        
        return solve(word1,word2,i,j,dp);
    }
};