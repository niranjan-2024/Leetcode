class Solution {
public:
    
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
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = s1[i] + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return sum - (2*dp[0][0]);
    }
};