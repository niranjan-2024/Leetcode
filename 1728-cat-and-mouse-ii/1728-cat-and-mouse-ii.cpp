class Solution {
public:
    
    int dp[75][8][8][8][8];
    vector<string> gridG;
    int cj,mj;
    int R,C;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    
    bool solve(int turns,int cx,int cy,int mx,int my){
        
        if(turns%2 == 1){
            if(mx == cx && my == cy){
                return false;
            }
            if(turns >= 75){
                return false;
            }
            if(gridG[mx][my] == 'F'){
                return true;
            }
            if(gridG[cx][cy] == 'F'){
                return false;
            }
        }
        else{
            if(mx == cx && my == cy){
                return true;
            }
            if(turns >= 75){
                return true;
            }
            if(gridG[mx][my] == 'F'){
                return false;
            }
            if(gridG[cx][cy] == 'F'){
                return true;
            }
        }
        
        if(dp[turns][cx][cy][mx][my] != -1){
            return dp[turns][cx][cy][mx][my];
        }
        
        bool IsWon = false;
        
        if(turns%2 == 1){
            for(int i=0;i<4;i++){
                for(int j=0;j<=mj;j++){
                    int Mx = mx + j*dr[i];
                    int My = my + j*dc[i];
                    
                    if(Mx>=0 && Mx<R && My>=0 && My<C && gridG[Mx][My] != '#'){
                        if(solve(turns+1,cx,cy,Mx,My) == 0){
                            IsWon = true;
                            break;
                        }
                    }
                    else break;
                }
                if(IsWon){
                   break;
                }
            }
        }
        else{
            for(int i=0;i<4;i++){
                for(int j=0;j<=cj;j++){
                    int Cx = cx + j*dr[i];
                    int Cy = cy + j*dc[i];
                    
                    if(Cx>=0 && Cx<R && Cy>=0 && Cy<C && gridG[Cx][Cy] != '#'){
                        if(solve(turns+1,Cx,Cy,mx,my) == 0){
                            IsWon = true;
                            break;
                        }
                    }
                    else break;
                }
                if(IsWon){
                   break;
                }
            }
        }
        
        return dp[turns][cx][cy][mx][my] = IsWon;
    }
    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        memset(dp,-1,sizeof(dp));
        gridG = grid;
        cj = catJump;
        mj = mouseJump;
        R = grid.size();
        C = grid[0].size();
        int cx,cy,mx,my;
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(gridG[i][j] == 'C'){
                    cx = i;
                    cy = j;
                }
                if(gridG[i][j] == 'M'){
                    mx = i;
                    my = j;
                }
            }
        }
        
        return solve(1,cx,cy,mx,my);
    }
};