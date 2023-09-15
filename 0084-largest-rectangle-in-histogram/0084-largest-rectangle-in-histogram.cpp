class Solution {
public:
        
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> pse(n),nse(n);
        stack<int> st;
        
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nse[st.top()] = n;
            st.pop();
        }
        
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            pse[st.top()] = -1;
            st.pop();
        }
        
        
        for(int i=0;i<n;i++){
            cout<<nse[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<pse[i]<<" ";
        }
        
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        
        return maxArea;
    }
};