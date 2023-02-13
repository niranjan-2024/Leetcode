class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int front = 0;
        int back = 0;
        int n = str.length();
        int ans = 0;
        
        while(back<n){
            if(back-front+1 < k){
                back++;
            }
            else if(back-front+1 == k){
                string temp = str.substr(front,k);
                int divisor = stoi(temp);
                
                if(divisor!=0 && num%divisor == 0){
                    ans++;
                }
                
                front++;
                back++;
            }
        }
        
        return ans;
    }
};