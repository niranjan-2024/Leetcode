class Solution {
public:
    
    static bool compare(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        
        unordered_map<string,int> dp;
        int ans = 0;
        
        for(string s:words){
            for(int i=0;i<s.length();i++){
                string pred = s.substr(0,i)+s.substr(i+1);
                dp[s] = max(dp[s],dp.find(pred) == dp.end() ? 1 : dp[pred]+1);
            }
            ans = max(ans,dp[s]);
        }
        
        return ans;
    }
};