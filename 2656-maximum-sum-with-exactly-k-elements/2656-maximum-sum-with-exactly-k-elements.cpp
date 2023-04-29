class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        
        int maxi = INT_MIN;
        for(auto it:nums){
            maxi = max(maxi,it);
        }
        
        int ans = 0;
        
        for(int i=0;i<k;i++){
            ans += maxi;
            maxi++;
        }
        
        return ans;
    }
};