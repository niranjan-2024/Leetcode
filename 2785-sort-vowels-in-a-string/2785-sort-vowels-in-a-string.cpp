class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        
        vector<char> vowels;
        vector<int> positions;
        
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U') { 
                vowels.push_back(s[i]);
                positions.push_back(i); 
            }
        }
        
        sort(vowels.begin(),vowels.end());
        
        string answer = s;
        
        for(int i=0;i<positions.size();i++){
            answer[positions[i]] = vowels[i];
        }
        
        return answer;
    }
};