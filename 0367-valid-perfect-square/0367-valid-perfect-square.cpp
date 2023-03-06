class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        long long right = num/2 + 1;
        long long mid;
        
        while(left<right){
            mid = left + (right-left)/2;
            if(right*right == num){
                    return true;
            }
            
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