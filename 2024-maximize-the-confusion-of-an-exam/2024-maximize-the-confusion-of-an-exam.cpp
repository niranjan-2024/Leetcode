class Solution {
public:
    
    int solve(string &answerKey,int k,char X){
        int i = 0;
        int j = 0;
        int result = 0;
        int n = answerKey.size();
        int countError = 0;
        
        while(j<n){
            if(answerKey[j] == X){
                countError++;
            }
            
            while(countError > k){
                if(answerKey[i] == X){
                    countError--;
                }
                i++;
            }
            
            result = max(j-i+1,result);
            j++;
        }
        
        return result;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
    }
};