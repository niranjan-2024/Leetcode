class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> m;
        
        for(auto rect : rectangles){
            int length = rect[0];
            int width = rect[1];
            
            int k = min(length,width);
            m[k]++;
        }
        
        int maxLen = 0;
        int ans = 0;
        
        for(auto it:m){
            if(it.first > maxLen){
                maxLen = it.first;
                ans = it.second;
            }
        }
        
        return ans;
    }
};