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
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxArea = 0;
        vector<int> height(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            
            int area = largestRectangleArea(height);
            maxArea = max(area,maxArea);
        }
        
        return maxArea;
    }
};