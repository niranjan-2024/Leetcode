class Solution {
public:
    
    int solve(vector<int> &nums1,vector<int> &nums2,int i,int j,vector<vector<int>> &dp){
        if(i == 0 || j == 0){
            return 0;
        }
        
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        
        dp[i][j] = nums1[i-1]*nums2[j-1] + max(solve(nums1,nums2,i-1,j-1,dp),0);
        
        if(j>1){
            dp[i][j] = max(dp[i][j],solve(nums1,nums2,i,j-1,dp));
        }
        if(i>1){
            dp[i][j] = max(dp[i][j],solve(nums1,nums2,i-1,j,dp));
        }
        
        return dp[i][j];
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MIN));
        
        return solve(nums1,nums2,n,m,dp);
    }
};