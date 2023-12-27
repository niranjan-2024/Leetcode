class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans = 0;
        
        for(int l=0,r=1 ; r<n;){
            if(colors[l] == colors[r]){
                if(neededTime[l] > neededTime[r]){
                    ans += neededTime[r];
                    r++;
                }
                else{
                    ans += neededTime[l];
                    r++;
                    l = r-1;
                }
            }
            else{
                r++;
                l = r-1;
            }
        }
        
        return ans;
    }
};