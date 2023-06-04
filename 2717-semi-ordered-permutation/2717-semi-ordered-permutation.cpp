class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int oneIndex;
        int nIndex;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                oneIndex = i;
            }
            if(nums[i] == n){
                nIndex = i;
            }
        }
        
        return (oneIndex<nIndex) ? (oneIndex+n-nIndex-1) : (oneIndex+n-nIndex-1)-1;
    }
};