class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size();
        int mid;
        
        while(left<right){
            mid = (left+right)/2;
            
            if(arr[mid]-1-mid < k){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        
        return left+k;
    }
};