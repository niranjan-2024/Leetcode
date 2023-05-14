class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        int rows = nums.size();
        int cols = nums[0].size();
        
        for(int i=0;i<rows;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        
        for(int j=0;j<cols;j++){
            int maxi = 0;
            for(int i=0;i<rows;i++){
                maxi = max(maxi,nums[i][j]);
            }
            ans += maxi;
        }
        
        return ans;
    }
};