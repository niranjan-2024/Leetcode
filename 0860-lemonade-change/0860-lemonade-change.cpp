class Solution {
public:
    
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for(int money:bills){
            if(money == 5){
                five++;
            }
            else if(money == 10){
                ten++;
                five--;
            }
            else if(ten>0){
                ten--;
                five--;
            }
            else{
                five -= 3;
            }
            
            if(five < 0){
                return false;
            }
        }
        
        return true;
    }
};