class Solution {
public:
    
    long long pow(int N,int P,long long modulo){
        if(P == 0){
            return 1;
        }
        if(P == 1){
            return N%modulo;
        }
        long long ans = 1;
        long long recursive = pow(N,P/2,modulo)%modulo;
        
        if(P%2){
            ans = (ans*N)%modulo;
        }
        
        return (ans*((recursive*recursive)%modulo))%modulo;
    }
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        reverse(s.begin(),s.end());
        long long hashAns = 0;
        string result;
        
        for(int i=0;i<s.size();i++){
            if(i<k){
                hashAns = (hashAns + ((s[i]-'a'+1)*pow(power,k-1-i,modulo))%modulo)%modulo;
                continue;
            }
            
            if(hashAns == hashValue){
                string tempAns = s.substr(i-k,k);
                //cout<<tempAns;
                reverse(tempAns.begin(),tempAns.end());
                result = tempAns;
            }
            
            hashAns = (hashAns + modulo - ((s[i-k]-'a'+1)*pow(power,k-1,modulo))%modulo)%modulo;
            hashAns = (hashAns*power)%modulo;
            hashAns = (hashAns+(s[i]-'a'+1))%modulo;
        }
        
        if(hashAns == hashValue){
            string tempAns = s.substr(s.size()-k,k);
            reverse(tempAns.begin(),tempAns.end());
            result = tempAns;
        }
        
        return result;
    }
};