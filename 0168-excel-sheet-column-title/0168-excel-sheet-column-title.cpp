class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string result;
        char temp;
        
        while(n){
            n--;
            temp = 'A' + n%26;
            result = temp + result;
            n = n/26;
        }
        
        return result;
    }
};