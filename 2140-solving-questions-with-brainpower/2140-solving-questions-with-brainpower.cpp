class Solution {
public:
    
    long long solve(vector<vector<int>>& questions,int index,vector<long long> &dp){
        if(index >= questions.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        return dp[index] = max(solve(questions,index+1,dp),questions[index][0]+solve(questions,index+questions[index][1]+1,dp));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
};