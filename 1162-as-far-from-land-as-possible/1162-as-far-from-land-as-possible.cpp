class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int steps = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 1){
                    q.push({row-1,col});
                    q.push({row+1,col});
                    q.push({row,col-1});
                    q.push({row,col+1});
                }
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            steps++;
            
            for(int k=0; k<size; k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                if(row>=0 && col>=0 && row<rows && col<cols && grid[row][col]==0){
                    grid[row][col] = steps;
                    q.push({row-1,col});
                    q.push({row+1,col});
                    q.push({row,col-1});
                    q.push({row,col+1});
                }
            }
        }
        
        return steps == 1 ? -1 : steps-1;
    }
};