class Solution {
public:
    
    int reverse(int num){
        int ans = 0;
        
        while(num){
            int digit = num%10;
            num /= 10;
            ans *= 10;
            ans += digit;
        }
        
        return ans;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        
        return st.size();
    }
};