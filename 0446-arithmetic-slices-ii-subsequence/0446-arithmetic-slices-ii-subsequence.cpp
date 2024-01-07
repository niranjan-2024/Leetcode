class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3){
            return 0;
        }
        
        int result = 0;
        
        unordered_map<long long,int> dp[n];
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                
                long long difference = (long long)nums[i] - (long long)nums[j];
                
                if(dp[j].find(difference) != dp[j].end()){
                    result = result + dp[j][difference];
                    dp[i][difference] = dp[i][difference] + dp[j][difference];
                }
                
                dp[i][difference]++;
            }
        }
        
        return result;
    }
};