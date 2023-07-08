class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        
        if(k == 1 || n == k) return 0;
        
        vector<int> barSum;
        for(int i=0;i<n-1;i++){
            barSum.push_back(weights[i]+weights[i+1]);
        }
        sort(barSum.begin(),barSum.end());
        
        long long maxi=0,mini=0;
        
        for(int i=0;i<k-1;i++){
            mini += barSum[i];
            maxi += barSum[n-2-i];
        }
        
        return maxi-mini;
    }
};