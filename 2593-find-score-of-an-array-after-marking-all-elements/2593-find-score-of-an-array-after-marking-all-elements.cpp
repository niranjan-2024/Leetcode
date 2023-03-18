class Solution {
public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first<b.first;
    }
    
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        unordered_map<int,bool> visited;
        long long ans = 0;
        
        for(int i=0;i<n;i++){
            if(visited[temp[i].second]){
                continue;
            }
            
            ans += temp[i].first;
            
            visited[temp[i].second] = true;
            visited[temp[i].second-1] = true;
            visited[temp[i].second+1] = true;
        }
        
        return ans;
    }
};