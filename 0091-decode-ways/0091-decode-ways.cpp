class Solution {
public:
    
    int solve(string s,int index,vector<int> &dp){
        int n = s.size();
        
        if(index >= n){
            return 1;
        }
        
        if(s[index] == '0'){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int temp = solve(s,index+1,dp);
        
        if( index<n-1 && (s[index] - '0')*10 + (s[index+1] - '0') <= 26){
            temp += solve(s,index+2,dp);
        }
        
        return dp[index] = temp;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};