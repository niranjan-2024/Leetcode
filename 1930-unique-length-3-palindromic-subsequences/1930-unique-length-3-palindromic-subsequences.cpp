class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> firstLastOccurance(26,{-1,-1});
        
        for(int i=0;i<s.length();i++){
            if(firstLastOccurance[s[i]-'a'].first == -1){
                firstLastOccurance[s[i]-'a'].first = i;
            }
            else{
                firstLastOccurance[s[i]-'a'].second = i;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<26;i++){
            if(firstLastOccurance[i].second != -1){
                unordered_set<char> st;
                
                for(int options = firstLastOccurance[i].first+1; options < firstLastOccurance[i].second; options++){
                    st.insert(s[options]);
                }
                
                ans += st.size();
            }
        }
        
        return ans;
    }
};