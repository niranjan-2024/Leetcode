class Solution {
public:
    string reformatNumber(string number) {
        string temp;
        string ans;
        
        int n = number.size();
        
        for(auto c:number){
            if(isdigit(c)){
                temp += c;
            }
        }
        
        int len = temp.size();
        
        while(len>0){
            if(len == 3 || len > 4){
                ans += temp.substr(0,3);
                temp.erase(0,3);
                len = len-3;
                ans += "-";
            }
            else{
                ans += temp.substr(0,2);
                temp.erase(0,2);
                ans += "-";
                len = len-2;
            }
        }
        
        ans.pop_back();
        return ans;
    }
};