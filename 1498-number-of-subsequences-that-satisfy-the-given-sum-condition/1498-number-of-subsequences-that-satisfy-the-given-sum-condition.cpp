class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int mod = 1000000007;
        int result = 0;
        int n = nums.size();
        int i=0;
        int j=n-1;
        
        vector<int> pow_2;
        pow_2.push_back(1);
        for(int k=1;k<=n;k++){
            pow_2.push_back((2*pow_2[k-1])%mod);
        }
        
        while(i<=j){
            if(nums[i]+nums[j] <= target){
                result += pow_2[j-i];
                result = result%mod;
                i++;
            }
            else{
                j--;
            }
        }
        
        return result;
    }
};