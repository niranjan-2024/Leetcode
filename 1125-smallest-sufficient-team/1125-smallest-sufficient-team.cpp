class Solution {
public:
    
    int req_mask,m;
    int dp[1<<16][64];
    bool choice[1<<16][64];
    
    int solve(vector<int> &peopleSkills,int i,int mask){
        if(mask == req_mask){
            return 0;
        }
        if(i == m){
            return 10000;
        }
        
        int &ans = dp[mask][i];
        
        if(ans != -1){
            return ans;
        }
        
        int take = solve(peopleSkills,i+1,mask|peopleSkills[i]) + 1;
        int noTake = solve(peopleSkills,i+1,mask);
        
        if(take<noTake){
            choice[mask][i] = true;
        }
        
        return ans = min(take,noTake);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        m = people.size();
        
        unordered_map<string,int> skills;
        
        for(int i=0;i<n;i++){
            skills[req_skills[i]] = i;
        }
        
        vector<int> peopleSkills;
        
        for(auto &v:people){
            int h = 0;
            for(string &skill:v){
                h |= 1<< skills[skill];
            }
            peopleSkills.push_back(h);
        }
        
        req_mask = (1<<n)-1;
        
        memset(dp,-1,1<<n+8);
        memset(choice,0,1<<n+6);
        
        solve(peopleSkills,0,0);
        
        vector<int> ans;
        
        for(int i=0,mask=0;i<m;i++){
            if(choice[mask][i]){
                ans.push_back(i);
                mask |= peopleSkills[i];
            }
            
            if(mask == req_mask){
                break;
            }
        }
        
        return ans;
    }
};