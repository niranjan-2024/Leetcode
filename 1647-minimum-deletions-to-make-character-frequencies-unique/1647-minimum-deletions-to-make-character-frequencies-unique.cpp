class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        
        for(auto c:s){
            freq[c-'a']++;
        }
        
        sort(freq.begin(),freq.end());
        
        int deleted = 0;
        
        for(int i=24;i>=0;i--){
            if(freq[i] == 0){
                break;
            }
            
            if(freq[i] >= freq[i+1]){
                int prevFreq = freq[i];
                freq[i] = max(0,freq[i+1]-1);
                deleted += prevFreq - freq[i];
            }
        }
        
        return deleted;
    }
};