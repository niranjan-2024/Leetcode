class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> plantsByTap(n+1,0);
        
        for(int i=0;i<ranges.size();i++){
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);
            plantsByTap[left] = max(plantsByTap[left],right-left);
        }
        
        int tapsNeeded = 0, currEnd = 0, curFarthest = 0;
        
        for(int i=0;i<plantsByTap.size()-1;i++){
            if(i > curFarthest){
                return -1;
            }
            
            curFarthest = max(curFarthest,i+plantsByTap[i]);
            
            if(i == currEnd){
                tapsNeeded++;
                currEnd = curFarthest;
            }
        }
        
        return curFarthest >= n ? tapsNeeded : -1;
    }
};