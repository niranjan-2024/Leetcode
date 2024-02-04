class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int start=0;
        int anslen= INT_MAX;
        int ansidx=-1;
        
        if(n<m){
            return "";
        }
        
        unordered_map<char,int>set;
        unordered_map<char,int>pattern;

        for(int i=0;i<t.size();i++){
            char ch=t[i];
            pattern[ch]++;
        }
        
          int count=0;
        
            for(int i=0;i<s.size();i++){

                    char ch=s[i];
                     set[ch]++;
                
                    if(set[ch]<=pattern[ch]){
                        count++;
                    }

                    if(count==t.size()){

                        while(set[s[start]]> pattern[s[start]] || pattern[s[start]]==0){
                            if(set[s[start]]> pattern[s[start]])
                                set[s[start]]--;

                             start++;
                        }
                        
                        int len= i-start+1;
                        
                        if(len<anslen){
                            anslen= len;
                            ansidx=start;
                        }
                    }
            }
        
            if(ansidx==-1){
                return "";
            }
            else{
                return s.substr(ansidx,anslen);
            }
    }
};