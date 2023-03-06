class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int left = 0;
        int right = (num)/2 + 1;
        long long mid;
        
        while(left<right){
            mid = left + (right-left)/2;
            
            if(mid*mid == num){
                return true;
            }
            else if(mid*mid<num){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        
        return false;
    }
};