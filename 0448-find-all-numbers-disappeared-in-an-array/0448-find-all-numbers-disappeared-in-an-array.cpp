class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<bool> ch(nums.size()+1,false);
        
        for(int i=0;i<nums.size();i++){
            ch[nums[i]] = true;
        }
        
        for(int i=1;i<ch.size();i++){
            if(!ch[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};