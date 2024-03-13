class Solution {
public:
    int pivotInteger(int n) {
        int total = 0;
        for(int i=1;i<=n;i++){
            total += i;
        }
        
        int prefix = 0;
        
        for(int i=1;i<=n;i++){
            prefix += i;
            if(prefix == total - prefix + i){
                return i;
            }
        }
        
        return -1;
    }
};