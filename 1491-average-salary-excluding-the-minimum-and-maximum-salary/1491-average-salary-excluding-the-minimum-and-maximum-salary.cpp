class Solution {
public:
    double average(vector<int>& salary) {
        long long int sum = 0;
        int n=salary.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(auto it:salary){
            sum += it;
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        
        return ((double)(sum-maxi-mini)/(n-2));
    }
};