class Solution {
public:
    
    const static int a = 0,e = 1,i = 2,o = 3,u = 4;
    const static int any = 5;
    int mod = 1e9+7;
    
    vector<vector<int>> followedBy = {{e},
                                      {a,i},  
                                      {a,e,o,u},
                                      {i,u},
                                      {a},
                                      {a,e,i,o,u}
                                     };
    
    int dp[200001][6];
    
    int countVowelPermutation(int n,int last = any) {
        if(n == 0){
            return 1;
        }
        if(dp[n][last]){
            return dp[n][last];
        }
        
        int ans = 0;
        
        for(int next:followedBy[last]){
            ans = (ans+countVowelPermutation(n-1,next))%mod;
        }
        
        return dp[n][last] = ans;
    }
};