class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int maxi = INT_MIN;
        int zeroes = 0;
        
        for(int end=0;end<nums.size();end++){
            if(nums[end] == 0){
                zeroes++;
            }
            
            while(zeroes>k){
                if(nums[start] == 0){
                    zeroes--;
                }
                
                start++;
            }
            
            maxi = max(maxi,end-start+1);
        }
        
        return maxi;
    }
};