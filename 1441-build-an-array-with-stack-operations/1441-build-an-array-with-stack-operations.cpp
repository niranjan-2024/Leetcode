class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int streamCurrent = 1;
        
        for(int i=0;i<target.size();i++){
            while(streamCurrent < target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                streamCurrent++;
            }
            streamCurrent++;
            ans.push_back("Push");
        }
        
        return ans;
    }
};