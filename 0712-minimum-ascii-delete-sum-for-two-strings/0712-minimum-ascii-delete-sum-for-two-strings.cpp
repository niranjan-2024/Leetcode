class Solution {
public:
    
    int LCS(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i == s1.length() || j == s2.length()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        
        if(s1[i] == s2[j]){
            ans = s1[i] + LCS(s1,s2,i+1,j+1,dp);
        }
        else{
            ans = max(LCS(s1,s2,i+1,j,dp),LCS(s1,s2,i,j+1,dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        int sum = 0;
        
        for(int i=0;i<n1;i++){
            sum += s1[i];
        }
        for(int i=0;i<n2;i++){
            sum += s2[i];
        }
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return sum - (2*(LCS(s1,s2,0,0,dp)));
    }
};