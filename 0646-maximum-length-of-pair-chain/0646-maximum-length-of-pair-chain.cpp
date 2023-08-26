class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int curr = INT_MAX;
        int ans = 0;
        
        for(int i=pairs.size()-1;i>=0;i--){
            if(pairs[i][1] < curr){
                ans++;
                curr = pairs[i][0];
            }
        }
        
        return ans;
    }
};