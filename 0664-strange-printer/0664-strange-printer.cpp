class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1));
        
        for(int len=0;len<s.size();len++){
            
            for(int start=0;start<(s.size()-len);start++){
                int end = start+len;
                
                dp[start][end] = len+1;
                
                for(int k=start+1;k<=end;k++){
                    int steps = dp[start][k-1] + dp[k][end] - (s[k-1] == s[end] ? 1 : 0);
                    dp[start][end] = min(dp[start][end],steps);
                }
            }
        }
        
        return dp[0][s.size()-1];
    }
};