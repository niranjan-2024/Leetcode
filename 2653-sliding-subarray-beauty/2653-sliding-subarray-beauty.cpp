class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51,0);
        vector<int> ans;
        
        for(int i=0,j=0;i<n;i++){
            if(nums[i]<0){
                freq[abs(nums[i])]++;
            }
            
            if(i-j+1 >= k){
                int count_negatives = 0;
                
                for(int e=50;e>=1;e--){
                    count_negatives += freq[e];
                    if(count_negatives >= x){
                        ans.push_back(-e);
                        break;
                    }
                }
                
                if(count_negatives < x){
                    ans.push_back(0);
                }
                
                if(nums[j] < 0){
                    freq[abs(nums[j])]--;
                }
                
                j++;
            }
        }
        
        return ans;
    }
};