class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        
        for(auto x : rectangles){
            mp[{x[0],x[1]}]++;
            mp[{x[2],x[3]}]++;
            mp[{x[0],x[3]}]--;
            mp[{x[2],x[1]}]--;
        }
        
        int corners = 0;
        
        for(auto it:mp){
            if(it.second != 0){
                if(it.second == -1 || it.second == 1){
                    corners++;
                }
                else{
                    return false;
                }
            }
        }
        
        return corners == 4;
    }
};