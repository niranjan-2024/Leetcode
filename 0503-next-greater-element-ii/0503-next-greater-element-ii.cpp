class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(0);
        vector<int> ans(n,-1);
        
        for(int i=1;i<2*n;i++){
            while(!st.empty() && nums[i%n] > nums[st.top()]){
                ans[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        
        return ans;
    }
};