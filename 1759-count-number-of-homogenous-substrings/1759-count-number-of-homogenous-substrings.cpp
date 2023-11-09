class Solution {
public:
    int countHomogenous(string s) {
        int count = 1;
        int result = 0;
        
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i] == s[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            
            result = (result+count)%1000000007;
        }
        
        return result;
    }
};