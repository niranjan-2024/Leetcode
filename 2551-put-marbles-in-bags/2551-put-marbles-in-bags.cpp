class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        
        vector<int> barsSum;
        for(int i=0;i<n-1;i++){
            barsSum.push_back(weights[i]+weights[i+1]);
        }
        
        sort(barsSum.begin(),barsSum.end());
        
        long long minSum = 0, maxSum = 0;
        
        for(int i=0;i<k-1;i++){
            minSum += barsSum[i];
            maxSum += barsSum[n-2-i];
        }
        
        return maxSum-minSum;
    }
};