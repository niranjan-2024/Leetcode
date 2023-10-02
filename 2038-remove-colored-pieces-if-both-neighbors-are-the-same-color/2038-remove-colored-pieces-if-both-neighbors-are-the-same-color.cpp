class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        
        int temp = 0;
        
        for(int i=0;i<colors.length();i++){
            char c = colors[i];
            if(c == 'A'){
                temp++;
            }
            else{
                if(temp > 2){
                    alice += (temp-2);
                    temp = 0;
                }
                else{
                    temp = 0;
                }
            }
        }
        
        if(temp > 2){
            alice += (temp-2);
            temp = 0;
        }
        else{
            temp = 0;
        }
        
        for(int i=0;i<colors.length();i++){
            char c = colors[i];
            if(c == 'B'){
                temp++;
            }
            else{
                if(temp > 2){
                    bob += (temp-2);
                    temp = 0;
                }
                else{
                    temp = 0;
                }
            }
        }
        
        if(temp > 2){
            bob += (temp-2);
            temp = 0;
        }
        else{
            temp = 0;
        }
        
        if(alice > bob){
            return true;
        }
        
        return false;
    }
};