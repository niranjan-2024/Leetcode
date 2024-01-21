class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        int[] array = new int[n];
        array[0]=nums[0];
        for(int i=1;i<n;++i){
            int take=nums[i];
            if(i>1)
                take+=array[i-2];
            int notake=array[i-1];
            array[i]=Math.max(take,notake);
        }
        return array[n-1];
    }
}