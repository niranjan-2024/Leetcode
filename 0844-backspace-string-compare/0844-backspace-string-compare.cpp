class Solution {
public:
    
    string getFinalString(string& s){
        int n = s.length();
        string result = "";
        int count = 0;
        
        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(ch == '#'){
                count++;
            }
            else{
                if(count>0){
                    count--;
                }
                else{
                    result = result + ch;
                }
            }
        }
        
        return result;
    }
    
    bool backspaceCompare(string s, string t) {
        return getFinalString(s) == getFinalString(t);
    }
};