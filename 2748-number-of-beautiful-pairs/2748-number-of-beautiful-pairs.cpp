class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            int first = nums[i];
            string num1 = to_string(first);
            
            for(int j=i+1;j<nums.size();j++){
                int second = nums[j];
                string num2 = to_string(second);
                
                int f = num1[0]-'0';
                int l = num2[num2.size()-1]-'0';
                
                if(__gcd(f,l) == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};