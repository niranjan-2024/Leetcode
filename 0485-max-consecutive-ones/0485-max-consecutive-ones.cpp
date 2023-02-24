class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                ans = max(ans,result);
                result = 0;
            }
            else{
                result++;
            }
        }
        
        return max(ans,result);
    }
};