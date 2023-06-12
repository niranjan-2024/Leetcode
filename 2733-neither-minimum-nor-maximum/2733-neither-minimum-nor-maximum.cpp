class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int n:nums){
            maxi = max(n,maxi);
            mini = min(n,mini);
        }
        
        for(int n:nums){
            if(n>mini && n<maxi){
                return n;
            }
        }
        
        return -1;
    }
};