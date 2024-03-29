class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<mat.size();i++){
            int ones = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    ones++;
                }
            }
            pq.push({ones,i});
        }
        
        vector<int> ans;
        
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};