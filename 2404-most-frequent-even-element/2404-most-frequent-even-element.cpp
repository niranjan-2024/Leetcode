class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto x:nums){
            mp[x]++;
        }
        
        int ans = -1;
        int count = 0;
        
        for(auto it:mp){
            if((it.first)%2 == 0 && ans == -1){
                ans = it.first;
                count = it.second;
            }
            else if((it.first)%2 == 0 && it.second > count){
                ans = it.first;
                count = it.second;
            }
            else if((it.first)%2 == 0 && it.second == count && it.first < ans){
                ans = it.first;
                count = it.second;
            }
        }
        
        return ans;
    }
};