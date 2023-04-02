class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
        
        for(int i=0;i<nums.size();i++){
            long long n = nums[i];
            
            if(i>indexDiff){
                window.erase(nums[i-indexDiff-1]);
            }
            
            auto position = window.lower_bound(n-valueDiff);
            
            if(position != window.end() && (*position-n) <= valueDiff) return true;
            
            window.insert(n);
        }
        
        return false;
    }
};