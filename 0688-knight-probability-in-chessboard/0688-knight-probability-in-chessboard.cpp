class Solution {
public:
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,0)));
        
        vector<vector<int>> directions = {{-2,-1},{-1,-2},{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2}};
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                dp[r][c][0] = 1;
            }
        }
        
        for(int K=1;K<=k;K++){
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    
                    double rate = 0;
                    
                    for(int i=0;i<directions.size();i++){
                        
                        int newR = r + directions[i][0];
                        int newC = c + directions[i][1];
                        
                        if(newR>=0 && newR<n && newC>=0 && newC<n){
                            rate += 0.125*dp[newR][newC][K-1];
                        }
                    }
                    
                    dp[r][c][K] = rate;
                }
            }
        }
        
        return dp[row][column][k];
    }
};