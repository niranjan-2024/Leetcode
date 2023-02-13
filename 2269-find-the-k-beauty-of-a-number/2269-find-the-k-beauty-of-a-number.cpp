class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int i=0;
        int j=0;
        int n = str.length();
        int ans = 0;
        
        while(j<n){
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                string temp = str.substr(i,k);
                int divisor = stoi(temp);
                
                if(divisor!=0 && num%divisor == 0){
                    ans++;
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};