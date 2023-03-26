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
            int uInd = upper_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            ans.push_back(((long long)queries[i]*uInd-prefix[uInd]) + ((prefix.back()-prefix[uInd])-(long long)queries[i]*(nums.size()-uInd)));
        }
        
        return ans;
    }
};