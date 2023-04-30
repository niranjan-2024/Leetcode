class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        long long int p1 = 0;
        long long int p2 = 0;
        
        for(int i=0;i<player1.size();i++){
            int x1 = player1[i];
            int x2 = player2[i];
            
            if(i>=1 && (player1[i-1] == 10 || (i>1 && player1[i-2] == 10))){
                p1 += (2*x1);
            }
            else{
                p1 += x1;
            }
            
            if(i>=1 && (player2[i-1] == 10 || (i>1 && player2[i-2] == 10))){
                p2 += (2*x2);
            }
            else{
                p2 += x2;
            }
        }
        
        if(p1>p2){
            return 1;
        }
        else if(p1<p2){
            return 2;
        }
        
        return 0;
    }
};