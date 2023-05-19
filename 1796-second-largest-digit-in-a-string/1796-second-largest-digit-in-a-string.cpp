class Solution {
public:
    int secondHighest(string s) {
        int first = -1;
        int second = -1;
        
        for(auto digit:s){
            if(digit >= '0' && digit <= '9'){
                if(digit-'0' > first){
                    second = first;
                    first = digit-'0';
                }
                else if(digit-'0' > second && digit-'0' != first){
                    second = digit-'0';
                }
            }
        }
        
        return second;
    }
};