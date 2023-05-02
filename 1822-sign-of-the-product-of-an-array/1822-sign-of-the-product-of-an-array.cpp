class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                return 0;
            }
            else if(nums[i]<0){
                negatives++;
            }
        }
        
        return negatives&1 ? -1:1;
    }
};