class Solution {
public:
    
    bool isValid(string s){
        int n = s.length();
        int hyphens = 0;
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                continue;
            }
            if(isdigit(s[i])){
                return false;
            }
            if((s[i] == '.' || s[i] == '!' || s[i] == ',')&&(i != n-1)){
                return false;
            }
            if(s[i] == '-'){
                if(hyphens || i == 0 || i == n-1 || !isalpha(s[i-1]) || !isalpha(s[i+1])){
                    return false;
                }
                hyphens++;
            }
        }
        
        return true;
    }
    
    int countValidWords(string sentence) {
        vector<string> words;
        
        istringstream ss(sentence);
        string curr;
        
        while(ss >> curr){
            words.push_back(curr);
        }
        
        int ans = 0;
        
        for(string s:words){
            if(isValid(s)){
                ans++;
            }
        }
        
        return ans;
    }
};