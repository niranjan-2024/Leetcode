class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> S,T;
        
        for(int i=0;i<s.length();i++){
            S[s[i]]++;
            T[t[i]]++;
        }
        
        int ans = 0;
        
        for(auto it:S){
            char c = it.first;
            int s_freq = it.second;
            int t_freq = T[c];
            
            if(t_freq-s_freq < 0){
                ans += abs(s_freq-t_freq);
            }
        }
        
        return ans;
    }
};