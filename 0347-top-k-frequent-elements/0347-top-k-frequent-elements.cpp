class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
        }

        vector<int> ans;
        while(ans.size()<k){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};