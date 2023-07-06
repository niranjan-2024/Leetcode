class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int mini = INT_MAX;
        int n = nums.size();
        
        while(j<n){
            sum += nums[j];
            j++;
            
            while(sum >= target){
                sum -= nums[i];
                i++;
                mini = min(mini,j-i+1);
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};