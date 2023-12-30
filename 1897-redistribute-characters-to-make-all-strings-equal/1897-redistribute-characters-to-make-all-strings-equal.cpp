class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        int sz = words.size();
        
        for(int i=0;i<sz;i++){
            string temp = words[i];
            for(int j=0;j<temp.length();j++){
                mp[temp[j]]++;
            }
        }
        
        for(auto it : mp){
            if(it.second % sz != 0){
                return false;
            }
        }
        
        return true;
    }
};