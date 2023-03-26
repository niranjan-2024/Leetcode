class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        
        vector<long long> prefix {0};
        for (int n : nums){
            prefix.push_back(prefix.back() + n);
        }
        
        vector<long long> ans;
        
        for(int i=0;i<queries.size();i++){
            int q = queries[i];
            int upperIndex = upper_bound(nums.begin(),nums.end(),q) - nums.begin();
            ans.push_back(((long long)q*upperIndex-prefix[upperIndex]) + ((prefix.back()-prefix[upperIndex])-(long long)q*(nums.size()-upperIndex)));
        }
        
        return ans;
    }
};