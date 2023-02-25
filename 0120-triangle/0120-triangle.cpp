class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n,0);
        vector<int> curr(n,0);
        
        prev = triangle[n-1];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                curr[j] = triangle[i][j] + min(prev[j],prev[j+1]);
            }
            prev = curr;
        }
        
        return prev[0];
    }
};