class Solution {
public:
    int trap(vector<int>& height) {
        //Find two max height on left as well as max height on right to make sure that the present can trap water
        int n = height.size();
        vector<int> leftmax(n) , rightmax(n);
        
        //For finding max on left
        for(int i=1;i<n;i++){
            leftmax[i] = max(height[i-1],leftmax[i-1]);
        }
        
        //for finding max on right
        for(int i=n-2;i>=0;i--){
            rightmax[i] = max(height[i+1],rightmax[i+1]);
        }
        
        //water level is minimum height from left and right max heights
        //if water level is greter than height then only we can add diffrence of two in the answer
        int ans = 0;
        for(int i=0;i<n;i++){
            int waterLevel = min(leftmax[i],rightmax[i]);
            if(waterLevel>height[i]){
                ans = ans + waterLevel - height[i];
            }
        }
        
        return ans;
    }
};