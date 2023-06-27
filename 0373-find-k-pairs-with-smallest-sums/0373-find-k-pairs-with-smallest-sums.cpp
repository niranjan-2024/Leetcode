class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans;
        
        if(n == 0 || m == 0){
            return ans;
        }
        
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(!pq.empty() && k>0){
            k--;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            ans.push_back({nums1[i],nums2[j]});
            
            if(j+1 == m){
                continue;
            }
            
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        
        return ans;
    }
};