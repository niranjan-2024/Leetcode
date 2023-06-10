class Solution {
public:
     int maxValue(int n, int index, int maxSum) {
        long long int ans = 1;
        long long int j = index;
        long long int len = j-index+1;
        maxSum -= n;
         
        while(len <= maxSum){
            maxSum -= len;
            j = min(n*1ll-1ll,j*1ll+1ll);
            index = max(0ll,index*1ll-1ll);
            len = j-index+1;
            ans++;
            if(len == n){
                break;
            }
        }
         
        ans += (maxSum/n);
         
        return ans;
    }
};