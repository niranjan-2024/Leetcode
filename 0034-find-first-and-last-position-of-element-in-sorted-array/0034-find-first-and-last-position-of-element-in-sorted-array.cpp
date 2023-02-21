class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int firstA,lastA;
        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(first != nums.size() && nums[first] == target) firstA = first;
        else firstA = -1;
        int last = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        if(last >= 0 && nums[last] == target) lastA = last;
        else lastA = -1;
        return {firstA,lastA};
    }
};