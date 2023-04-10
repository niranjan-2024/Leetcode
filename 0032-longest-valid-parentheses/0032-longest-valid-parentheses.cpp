class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int longest = 0;
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    st.push(i);
                }
                else{
                    if(s[st.top()] == '('){
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
            }
        }
        
        if(st.empty()){
            return n;
        }
        else{
            int a = n;
            int b = 0;
            
            while(!st.empty()){
                b = st.top();
                st.pop();
                longest = max(longest,a-b-1);
                a = b;
            }
            
            longest = max(longest,a);
        }
        
        return longest;
    }
};