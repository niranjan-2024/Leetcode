class Solution {
public:
    string getPermutation(int n, int k) {
        string first = "";
        
        for(int i=1;i<=n;i++){
            first += to_string(i);
        }
        
        for(int i=0;i<k-1;i++){
            next_permutation(first.begin(),first.end());
        }
        
        return first;
    }
};