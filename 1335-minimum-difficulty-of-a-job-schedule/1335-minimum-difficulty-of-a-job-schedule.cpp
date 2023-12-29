class Solution {
public:
    
    int maxDays;
    vector<int> jobDifficulty;
    const int INF = 99999999;
    int n;
    int dp[302][11];
    
    int solve(int index,int daysLeft){
        
        if(daysLeft == 0 && index == n){
            return 0;
        }
        
        if(index == n || daysLeft == 0){
            return INF;
        }
        
        if(dp[index][daysLeft] != -1){
            return dp[index][daysLeft];
        }
        
        int result = INF;
        int dayMaxDifficulty = 0;
        
        for(int i=index;i<n;i++){
            dayMaxDifficulty = max(dayMaxDifficulty,jobDifficulty[i]);
            result = min(result , dayMaxDifficulty + solve(i+1,daysLeft-1));
        }
        
        return dp[index][daysLeft] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this -> jobDifficulty = jobDifficulty;
        maxDays = d;
        memset(dp,-1,sizeof(dp));
        
        n = jobDifficulty.size();
        
        if(n<d){
            return -1;
        }
        
        return solve(0,d);
    }
};