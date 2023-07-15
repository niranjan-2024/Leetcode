class Solution {
public:
    
    int solve(vector<vector<int>> &events,int n,int pos,int k,vector<vector<int>> &dp){
        if(pos>=n || k==0){
            return 0;
        }
        
        if(dp[pos][k] != -1){
            return dp[pos][k];
        }
        
        int i;
        
        vector<int> temp = {events[pos][1],99999,99999};
        i = upper_bound(events.begin()+pos+1,events.end(),temp)-events.begin();
        
        return dp[pos][k] = max(solve(events,n,pos+1,k,dp),events[pos][2]+solve(events,n,i,k-1,dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return solve(events,n,0,k,dp);
    }
};