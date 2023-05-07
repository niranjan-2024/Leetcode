class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<pair<int,int>> v(nums.size());
        vector<int> ans;
        set<int> prefix,suffix;
        
        for(int i=0;i<nums.size();i++){
            suffix.insert(nums[i]);
            v[i].second = suffix.size();
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            v[i].first = prefix.size();
            prefix.insert(nums[i]);
        }
        
        for(auto it:v){
            ans.push_back(it.second-it.first);
        }
        
        return ans;
    }
};