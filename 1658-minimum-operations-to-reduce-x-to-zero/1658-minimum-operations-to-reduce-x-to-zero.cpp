class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sumOfAll = 0;
        int n = nums.size();
        
        for(auto it : nums){
            sumOfAll += it;
        }
        
        int targetSum = sumOfAll - x;
        int currSum = 0;
        int maxLen = 0;
        int start = 0;
        bool requiredWindowFound = 0;
        
        for(int end=0;end<n;end++){
            currSum += nums[end];
            
            while(start<=end && currSum>targetSum){
                currSum -= nums[start];
                start += 1;
            }
            
            if(currSum == targetSum){
                requiredWindowFound = true;
                maxLen = max(maxLen,end-start+1);
            }
        }
        
        return requiredWindowFound ? n - maxLen : -1;
    }
};