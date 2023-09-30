class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s1;
        int s3 = INT_MIN;
        
        stack<int> st;
        
        for(int i=nums.size()-1;i>=0;i--){
            s1 = nums[i];
            
            if(s1 < s3){
                return true;
            }
            
            while(!st.empty() && s1>st.top()){
                s3 = st.top();
                st.pop();
            }
            
            st.push(s1);
        }
        
        return false;
    }
};