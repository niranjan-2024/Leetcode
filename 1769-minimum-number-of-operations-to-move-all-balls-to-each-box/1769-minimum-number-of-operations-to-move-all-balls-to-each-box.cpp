class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n,0);
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int count = 0;
        prefix[0] = 0;
        suffix[n-1] = 0;
        
        for(int i=1;i<n;i++){
            if(boxes[i-1] == '1'){
                count++;
                prefix[i] = prefix[i-1] + count;
            }
            else{
                prefix[i] = prefix[i-1] + count;
            }
        }
        
        count = 0;
        
        for(int i=n-2;i>=0;i--){
            if(boxes[i+1] == '1'){
                count++;
                suffix[i] = suffix[i+1] + count;
            }
            else{
                suffix[i] = suffix[i+1] + count;
            }
        }
        
        for(int i=0;i<n;i++){
            ans[i] = prefix[i] + suffix[i];
        }
        
        return ans;
    }
};