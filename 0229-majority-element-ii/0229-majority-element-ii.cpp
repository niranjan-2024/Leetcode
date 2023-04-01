class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int y = -1;
        int z = -1;
        int cy = 0;
        int cz = 0;
        
        for(auto x:nums){
            if(x == y) cy++;
            else if(x == z) cz++;
            else if(!cy) y = x , cy = 1;
            else if(!cz) z = x , cz = 1;
            else cy-- , cz--;
        }
        
        cy = cz = 0;
        
        for(auto x:nums){
            if(x == y) cy++;
            else if(x == z) cz++;
        }
        
        vector<int> result;
        
        if(cy > nums.size()/3) result.push_back(y);
        if(cz > nums.size()/3) result.push_back(z);
        
        return result;
    }
};