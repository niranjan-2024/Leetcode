class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m+n-1;
        int right = 0;
        
        while(right<n){
            //if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
            left--;
            right++;
            //}
            // else{
            //     break;
            // }
        }
        
        sort(nums1.begin(),nums1.end());
    }
};