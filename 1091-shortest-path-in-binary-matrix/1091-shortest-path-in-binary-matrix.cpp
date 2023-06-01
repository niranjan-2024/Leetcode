class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,m-1};
        
        if(grid[0][0] != 0){
            return -1;
        }
        
        if(source.first ==  destination.first && source.second == destination.second){
            return 1;
        }
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        
        distance[source.first][destination.first] = 0;
        q.push({0,{source.first,source.second}});
        
        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,1,0,1,-1,-1,1,0};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int currDistance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            for(int i=0;i<8;i++){
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==0 && currDistance+1 < distance[newRow][newCol]){
                    distance[newRow][newCol] = 1+currDistance;
                    
                    if(newRow == destination.first && newCol == destination.second){
                        return currDistance+1+1;
                    }
                    
                    q.push({1+currDistance,{newRow,newCol}});
                }
            }
        }
        
        return -1;
    }
};