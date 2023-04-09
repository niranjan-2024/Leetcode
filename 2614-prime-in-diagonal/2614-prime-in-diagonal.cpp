class Solution {
public:
    
    bool is_prime(int n){
        if(n<=2 || n%2 == 0){
            return n==2;
        }
        for(int i=3;i*i<=n;i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int largest_prime = 0;
        
        for(int i=0;i<nums.size();i++){
            largest_prime = max(largest_prime,max(is_prime(nums[i][i])*nums[i][i],is_prime(nums[i][nums.size()-i-1])*nums[i][nums.size()-i-1]));
        }
        
        return largest_prime;
    }
};