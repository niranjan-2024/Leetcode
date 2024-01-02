class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int highestFreq = 0;
        
        for(auto a : nums){
            mp[a]++;
            highestFreq = max(highestFreq,mp[a]);
        }
        
        vector<vector<int>> resultant(highestFreq);
        
        for(auto it : mp){
            int element = it.first;
            int frequency = it.second;
            
            for(int i=0;i<frequency;i++){
                resultant[i].push_back(element);
            }
        }
        
        return resultant;
    }
};