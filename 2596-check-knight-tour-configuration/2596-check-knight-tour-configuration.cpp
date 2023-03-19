class Solution {
    int dr[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dc[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        
        queue<pair<int, int>>q;
        q.push({0, 0});
        
        int k=0;
        
        while(!q.empty())
        {
            int check = 0;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<8; i++)
            {
                int nx = x+dr[i], ny = y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==k+1)
                {   x = nx,y = ny;
                    check = 1;
                    break;
                }
            }
            
            if(check) {
                q.push({x,y});
            }
            
            k++;
        }
        return k==(n*n) ? 1 : 0;
    }
};