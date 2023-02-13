class Solution {
public:
    
    void solve(vector<int> &options,vector<string> &ans,int num,int current,int index,int hour,int min){
        if(hour > 11 || min > 59){
            return; 
        }
        
        if(current == num){
            string temp = to_string(hour) + ":" + ((min<10)?"0":"") + to_string(min);
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<options.size();i++){
            if(i<4){
                solve(options,ans,num,current+1,i+1,hour+options[i],min);
            }
            else{
                solve(options,ans,num,current+1,i+1,hour,min+options[i]);
            }
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> options = {1,2,4,8,1,2,4,8,16,32};
        vector<string> ans;
        solve(options,ans,turnedOn,0,0,0,0);
        return ans;
    }
};