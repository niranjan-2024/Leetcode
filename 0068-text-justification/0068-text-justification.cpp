class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        
        while(i < words.size()){
            int lettersCount = words[i].length();
            int j = i+1;
            
            int spacesAfterEach = 0;
            
            while(j<words.size() && lettersCount+spacesAfterEach+words[j].length()+1 <= maxWidth){
                lettersCount += words[j].length();
                j++;
                spacesAfterEach++;
            }
            
            int vacantSpaces = maxWidth - lettersCount;
            int betweenSpacesRequired = j-i-1;
            
            int SpacesForAll = betweenSpacesRequired == 0 ? 0 : vacantSpaces/betweenSpacesRequired;
            int extraSpaces = betweenSpacesRequired == 0 ? 0 : vacantSpaces%betweenSpacesRequired;
            
            if(j == words.size()){
                SpacesForAll = 1;
                extraSpaces = 0;
            }
            
            string temp = "";
            
            for(int k=i;k<j;k++){
                temp += words[k];
                
                if(k == j-1){
                    break;
                }
                
                for(int sp=0;sp<SpacesForAll;sp++){
                    temp += " ";
                }
                
                if(extraSpaces > 0){
                    temp += " ";
                    extraSpaces--;
                }
            }
            
            while(temp.length() < maxWidth){
                temp += " ";
            }
            
            ans.push_back(temp);
            
            i = j;
        }
        
        return ans;
    }
};