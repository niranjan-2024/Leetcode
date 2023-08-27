class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        mp[stones[0]+1] = {1};
        
        for(int i=1;i<stones.size();i++){
            int position = stones[i];
            
            for(auto prevJump : mp[position]){
                mp[position + prevJump].insert(prevJump);
                mp[position + prevJump + 1].insert(prevJump+1);
                mp[position + prevJump - 1].insert(prevJump-1);
            }
        }
        
        return mp[stones.back()].size() != 0;
    }
};