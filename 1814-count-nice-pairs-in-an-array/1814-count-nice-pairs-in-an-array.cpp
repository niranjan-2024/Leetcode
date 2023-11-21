class Solution {
public:
    
    int reverse(int temp){
        long long int ans = 0;

        while(temp != 0){
            int digit = temp%10;
            temp /= 10;
            ans += digit;
            ans *= 10;
        }

        ans /= 10;
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        vector<int> temp = nums;
        
        for(int i=0;i<nums.size();i++){
            temp[i] -= reverse(temp[i]);
        }
        sort(temp.begin(),temp.end());
        
        long long int ans = 0;
        int mod = 1000000007;
        
        for(int i=0;i<nums.size()-1;i++){
            long long int count = 1;
            while(i<nums.size()-1 && temp[i] == temp[i+1]){
                count++;
                i++;
            }
            
            ans += count*(count-1)/2;
            ans %= mod;
        }
        
        return ans%mod;
    }
};