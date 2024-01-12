class Solution {
public:
   bool checkVowel(char ch){
       if( ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ||  ch=='A' || ch=='E' || ch=='I' ||  ch=='O' || ch=='U' ){
           return true;
       }
       return false;
   }
    
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;
        
        int mid = s.size()/2;
        
        for(int i=0;i<mid;i++){
            if(checkVowel(s[i])){
                count1++;
            }
        }
        
        for(int i=mid;i<s.size();i++){
            if(checkVowel(s[i])){
                count2++;
            }
        }
        
        if(count1 == count2){
            return true;
        }
        
        return false;
    }
};