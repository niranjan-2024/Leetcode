class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        
        for(auto spell:spells){
            long long int need = success%spell == 0 ? success/spell : success/spell+1;
            auto it = lower_bound(potions.begin(),potions.end(),need)-potions.begin();
            ans.push_back(potions.size()-it);
        }
        
        return ans;
    }
};