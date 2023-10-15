class Solution {
public:
    int mod = (1000000007);
    int arrLen;
    vector<vector<int>> dp;
    
    int solve(int index,int steps){
        if(index == 0 && steps == 0){
            return 1;
        }
        if(index < 0 || index >= arrLen || steps == 0 || index > steps){
            return 0;
        }
        
        if(dp[index][steps] != -1){
            return dp[index][steps];
        }
        
        return dp[index][steps] = ((long long)solve(index+1,steps-1)%mod + (long long)solve(index,steps-1)%mod + (long long)solve(index-1,steps-1)%mod)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        dp.resize(steps/2 + 1, vector<int>(steps+1,-1));
        this->arrLen = arrLen;
        return solve(0,steps);
    }
};