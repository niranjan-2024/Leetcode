class Solution {
public:
    
    int dp[101][201];
    
    int help(int index, int M, vector<int> &piles){
        if(index >= piles.size()){
            return 0;
        }
        
        if(dp[index][M] != -1){
            return dp[index][M];
        }
        
        int total = 0;
        int difference = INT_MIN;
        
        for(int j=0;j<2*M;j++){
            if(index+j < piles.size()){
                total += piles[index+j];
            }
            
            difference = max(difference,total-help(index+j+1,max(M,j+1),piles));
        }
        
        return dp[index][M] = difference;
    }
    
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        
        memset(dp,-1,sizeof dp);
        
        for(auto a:piles){
            sum += a;
        }
        
        int difference = help(0,1,piles);
        
        return (sum + difference)/2;
    }
};