class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> res;
        
        if(m == 0 || n == 0){
            return res;
        }
        
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(!pq.empty() && k>0){
            k--;
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            res.push_back({nums1[i],nums2[j]});
            
            if(j+1 == m){
                continue;
            }
            
            pq.push({nums1[i]+nums2[j+1] , {i,j+1}});
        }
        
        return res;
    }
};