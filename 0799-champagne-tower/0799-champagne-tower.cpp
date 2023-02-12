class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass(query_row+1,vector<double>(query_row+1,0));
        
        glass[0][0] = poured;
        
        for(int i=0;i<query_row;i++){
            for(int j=0;j<i+1;j++){
                double amount = glass[i][j];
                
                if(amount>1){
                    glass[i][j] = 1;
                    amount -= 1;
                    glass[i+1][j] += amount/2;
                    glass[i+1][j+1] += amount/2;
                }
            }
        }
        
        if(glass[query_row][query_glass] > 1){
            return 1;
        }
        
        return glass[query_row][query_glass];
    }
};