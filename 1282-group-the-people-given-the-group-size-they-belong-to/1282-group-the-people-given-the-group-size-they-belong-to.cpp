class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        
        for(auto it:mp){
            
            int TotalElements = it.second.size();
            int groupSize = it.first;
            
            int i=0;
            vector<int> temp;
            
            while(i<TotalElements){
                if(i%groupSize == 0 && i!=0){
                    ans.push_back(temp);
                    temp.clear();
                }
                
                temp.push_back(it.second[i]);
                i++;
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};