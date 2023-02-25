class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        
        for(int i=1;i<n;i++){
            int difference = prices[i]-mini;
            profit = max(profit,difference);
            mini = min(mini,prices[i]);
        }
        
        return profit;
    }
};