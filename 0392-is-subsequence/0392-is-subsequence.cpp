class Solution {
public:
    bool isSubsequence(string s, string t) {
        int checkLen = 0;
        int j_check = 0;
        int j = 0;
        bool check = false;
        
        for(int i=0;i<s.size();i++){
            bool check = false;
            
            for(j=j_check;j<t.size();j++){
                if(t[j] == s[i]){
                    check = true;
                    j_check = j+1;
                    checkLen++;
                    break;
                }
            }
            
            if(!check){
                return false;
            }
        }
        
        if(checkLen != s.length()){
            return false;
        }
        
        return true;   
    }
};