class Solution {
public:
    
    int a=0 , e=1 , i=2, o=3, u=4;
    int MOD = 1e9+7;
    
    int countVowelPermutation(int n) {
        vector<long long> dp(5,1LL), prev(5,1LL);
        
        while(n-- > 1){
            dp[a] = (prev[e] + prev[i] + prev[u])%MOD;
            dp[e] = (prev[a] + prev[i])%MOD;
            dp[i] = (prev[e] + prev[o])%MOD;
            dp[o] = (prev[i])%MOD;
            dp[u] = (prev[i] + prev[o])%MOD;
            
            swap(dp,prev);
        }
        
        return accumulate(prev.begin(),prev.end(),0LL)%MOD;
    }
};