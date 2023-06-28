class Solution {
public:
    
    int countDivisors(int num,int &sum){
        int count = 0;
        
        for(int i=1;i<=num/2;i++){
            if(num%i == 0){
                count++;
                sum += i;
            }
            
            if(count>4){
                break;
            }
        }
        
        sum += num;
        return count+1;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            if(countDivisors(nums[i],sum) == 4){
                ans += sum;
            }
        }
        
        return ans;
    }
};