class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> lasers;
        
        for(int i=0;i<bank.size();i++){
            string temp = bank[i];
            int laser = 0;
            
            for(auto ch : temp){
                if(ch == '1'){
                    laser++;
                }
            }
            
            if(laser != 0){
                lasers.push_back(laser);   
            }
        }
        
        int ans = 0;
        
        for(int i=1;i<lasers.size();i++){
            ans += lasers[i]*lasers[i-1];
        }
        
        return ans;
    }
};