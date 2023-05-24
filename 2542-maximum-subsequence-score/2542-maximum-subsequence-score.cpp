class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size();
        long long sum = 0;
        long long ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=n-1;i>=0;i--){
            pq.push(v[i].second);
            sum += v[i].second;
            
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k){
                ans = max(ans,v[i].first*sum);
            }
        }
        
        return ans;
    }
};