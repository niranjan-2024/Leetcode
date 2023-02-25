class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int pair = 0;
        int left = 0;
        
        for(auto n:nums){
            mp[n]++;
        }
        
        for(auto it:mp){
            if(it.second%2){
                left += it.second%2;
            }
            pair += it.second/2;
        }
        
        return {pair,left};
    }
};