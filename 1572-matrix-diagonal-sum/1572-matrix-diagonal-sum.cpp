class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        
        for(int i=0;i<mat.size();i++){
            ans += (mat[i][i] + mat[mat.size()-1-i][i]);
        }
                
        return mat.size()&1 ? (ans-mat[mat.size()/2][mat.size()/2]) : ans;
    }
};