class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,set<pair<int,int>> &coordinates,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1 || coordinates.count({i,j})){
            return;
        }
        
        coordinates.insert({i,j});
        grid[i][j] = 2;
        
        for(int r=-1;r<=1;r++){
            for(int c=-1;c<=1;c++){
                if(abs(r-c) == 1){
                    dfs(grid,coordinates,i+r,j+c);
                }
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int,int>> coordinates_1,coordinates_2;
        int n = grid.size();
        
        int check = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(check == 0){
                        dfs(grid,coordinates_1,i,j);
                        check = 1;
                    }
                    else{
                        dfs(grid,coordinates_2,i,j);
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        
        for(auto i:coordinates_1){
            for(auto j:coordinates_2){
                ans = min(ans,abs(i.first-j.first)+abs(i.second-j.second)-1);
            }
        }
        
        return ans;
    }
};