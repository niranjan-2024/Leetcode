class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        int zeroes = 0;
        
        for(end=0;end<n;end++){
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