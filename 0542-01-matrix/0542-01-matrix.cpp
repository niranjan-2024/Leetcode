class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;
            
            for(int i=0;i<4;i++){
                int neighbourRow = row + deltaRow[i];
                int neighbourCol = col + deltaCol[i];
                
                if(neighbourRow>=0 && neighbourRow<n && neighbourCol>=0 && neighbourCol<m && visited[neighbourRow][neighbourCol]==0){
                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({{neighbourRow,neighbourCol},steps+1});
                }
            }
        }
        return distance;
    }
};