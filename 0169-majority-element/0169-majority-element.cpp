class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority_ele = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(count == 0){
                count = 1;
                majority_ele = nums[i];
            }
            else if(majority_ele == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        return majority_ele;
    }
};