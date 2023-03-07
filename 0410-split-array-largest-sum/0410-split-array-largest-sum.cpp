class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            left = max(left,nums[i]);
            right += nums[i];
        }
        
        while(left<=right){
            int mid = left + (right-left)/2;
            int tempSum = 0;
            int count = 0;
            
            for(int i=0;i<nums.size();i++){
                if(tempSum + nums[i] <= mid){
                    tempSum += nums[i];
                }
                else{
                    count++;
                    tempSum = nums[i];
                }
            }
            count++;
            
            if(count<=k){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        return ans;
    }
};