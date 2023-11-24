class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        
        int n = piles.size();
        int t = (2*n)/3;
        
        int ans = 0;
        
        for(int i=0;i<t;i++){
            if(i%2){
                // cout<<piles[i]<<endl;
                ans += piles[i];
            }
        }
        
        return ans;
    }
};