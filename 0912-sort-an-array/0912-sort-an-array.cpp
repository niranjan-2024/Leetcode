class Solution {
public:
    
    void merge(vector<int> &nums,int low,int mid,int high){
        int len = high-low+1;
        int gap = (len/2)+(len%2);
        
        while(gap>0){
            int left = low;
            int right = low + gap;
            
            while(right <= high){
                if(nums[left]>=nums[right]){
                    swap(nums[left],nums[right]);
                }
                left++,right++;
            }
            
            if(gap == 1){
                break;
            }
            
            gap = (gap/2) + (gap%2);
        }
    }
    
    void mergeSort(vector<int> &nums,int low,int high){
        if(low == high || low >= high){
            return;
        }
        
        int mid = (low+high)/2;
        
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        
        merge(nums,low,mid,high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};