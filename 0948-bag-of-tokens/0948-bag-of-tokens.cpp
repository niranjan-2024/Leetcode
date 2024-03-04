class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int i=0;
        int j=tokens.size()-1;
        int points=0;
        
        sort(tokens.begin(),tokens.end());
        
        while(i<=j && points>=0){
            if(tokens[i]<=power){
                power-=tokens[i++];
                ans =max(ans,++points);
            }
            else{
              power+=tokens[j--];
                --points;
            }
        }
        return ans;
    }
};