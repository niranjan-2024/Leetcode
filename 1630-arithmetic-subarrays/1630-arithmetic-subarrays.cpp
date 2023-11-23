class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<vector<int>> arr;
        
        for(int i=0;i<l.size();i++){
            vector<int> temp;
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            arr.push_back(temp);
        }
        
        vector<bool> ans;
        
        for(auto it: arr){
            if(it.size() == 2){
                ans.push_back(true);
            }
            else{
                sort(it.begin(),it.end());
                int diff = it[1]-it[0];
                bool check = true;
                for(int i=1;i<it.size();i++){
                    if(it[i]-it[i-1] != diff){
                        check = false;
                    }
                }
                
                if(check){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        
        return ans;
    }
};