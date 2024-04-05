class Solution {
public:
    string makeGood(string s) {
        for(int i=1;i<s.size();i++){
            if(i>=1 && ((s[i]-'a' == s[i-1]-'A')||(s[i]-'A' == s[i-1]-'a'))){
                s.erase(s.begin()+i-1,s.begin()+i+1);
                i = i-2;
            }
        }
        return s;
    }
};