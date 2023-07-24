class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            string s = words[i];
            string temp = "";
            
            for(auto ch:s){
                if(ch == separator && temp!=""){
                    ans.push_back(temp);
                    temp = "";
                }
                else if(ch != separator){
                    temp += ch;
                }
            }
            
            if(temp != ""){
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};