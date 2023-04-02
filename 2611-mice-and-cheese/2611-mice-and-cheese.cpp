class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum = 0;
        int n = reward1.size();
        
        vector<pair<int,int>> nums;
        
        for(int i=0;i<n;i++){
            nums.push_back({reward1[i]-reward2[i],i});
        }
        
        sort(nums.rbegin(),nums.rend());
        
        int i;
        
        for(i=0;i<k;i++){
            sum += reward1[nums[i].second];
        }
        
        for(;i<n;i++){
            sum += reward2[nums[i].second];
        }
        
        return sum;
    }
};