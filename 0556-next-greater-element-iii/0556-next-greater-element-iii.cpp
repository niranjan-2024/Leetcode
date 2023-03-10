class Solution {
public:
    
    bool nextPer(string& nums){
        if(nums.empty()){
            return false;
        }
        int i = nums.size()-1;
        while(i>=1 && nums[i]<=nums[i-1]){
            i--;
        }
        if(i == 0){
            return false;
        }
        
        int j = nums.size()-1;
        while(nums[j] <= nums[i-1]){
            j--;
        }
        
        swap(nums[i-1],nums[j]);
        
        reverse(nums.begin()+i,nums.end());
        return true;
    }
    
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        if(!nextPer(nums)){
            return -1;
        }
        auto ans = stoll(nums);
        return (ans>INT_MAX || ans<=n) ? -1 : ans;
    }
};