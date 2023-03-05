#define MOD 1000000007
class Solution {
public:
    
    int solve(int i,vector<vector<int>> &dp,int target,vector<vector<int>>& types,int n){
        if(target == 0){
            return 1;
        }
        if(i == n){
            return target == 0;
        }
        if(dp[i][target] != -1){
            return dp[i][target]%MOD;
        }
        
        long long result = 0;
        for(int j=0;j<=types[i][0];j++){
            if(target - types[i][1]*j >= 0){
                result += solve(i+1,dp,target-types[i][1]*j,types,n);
            }
            else{
                break;
            }
        }
        
        return dp[i][target] = result%MOD;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(types.size()+5,vector<int>(target+5,-1));
        return solve(0,dp,target,types,types.size());
    }
};