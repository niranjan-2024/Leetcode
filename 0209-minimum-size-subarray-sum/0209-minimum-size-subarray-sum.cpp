class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int mini = INT_MAX;
        int sum = 0;
        
        while(j<n){
            sum = sum + nums[j];
            j++;
            
            while(sum >= target){
                sum = sum - nums[i];
                i++;
                mini = min(mini,j-i+1);
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};