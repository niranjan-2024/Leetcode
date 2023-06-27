class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long ans = 0;
        int i = 0;
        int j = costs.size()-1;
        
        while(k>0){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j]);
                j--;
            }
            
            int first_smallest = pq1.size()>0?pq1.top():INT_MAX;
            int second_smallest = pq2.size()>0?pq2.top():INT_MAX;
            
            if(first_smallest<=second_smallest){
                ans += first_smallest;
                pq1.pop();
            }
            else{
                ans += second_smallest;
                pq2.pop();
            }
            
            k--;
        }
        
        return ans;
    }
};