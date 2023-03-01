class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> nums;
        int temp = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                temp = temp*10 + (s[i]-'0');
            }
            else{
                if(temp != 0){
                    nums.push_back(temp);
                    temp = 0;
                }
            }
        }
        
        if(temp!=0){
            nums.push_back(temp);
        }
        
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] >= nums[i]){
                return false;
            }
        }
        
        return true;
    }
};