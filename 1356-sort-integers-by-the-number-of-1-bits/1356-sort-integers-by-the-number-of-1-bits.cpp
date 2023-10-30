class Solution {
public:
    
    static int numberof1s(int a){
        int count = 0;
        while(a){
            a = a&(a-1);
            count++;
        }
        return count;
    }
    
    static bool compare(int a,int b){
        int bitsInA = numberof1s(a);
        int bitsInB = numberof1s(b);
        
        if(bitsInA == bitsInB){
            return a <= b;
        }
        else{
            return bitsInA < bitsInB;
        }
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};