class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        
        int left = 0;
        int righ = sum;

        vector<int> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            righ -= n;

            result[i] = n * i - left + righ - n * (nums.size() - i - 1);

            left += n;
        }

        return result;
    }
};