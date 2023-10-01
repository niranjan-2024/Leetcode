class Solution {
public:
    string reverseWords(string s) {
        vector<string> rs;
        string res = "";
        
        string temp = "";
        
        for(char c:s){
            if(c == 32){
                rs.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        rs.push_back(temp);
        
        for(string st:rs){
            reverse(st.begin(),st.end());
            res += st;
            res += " ";
        }
        
        res = res.substr(0,res.length()-1);
        
        return res;
    }
};