class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int sz = nums1.size();
        vector<int> ans(sz);
        unordered_map<int,int> mp;
        st.push(nums2[0]);
        
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>st.top()){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0;i<sz;i++){
            if(mp.count(nums1[i])){
                ans[i] = mp[nums1[i]];
            }
            else{
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};