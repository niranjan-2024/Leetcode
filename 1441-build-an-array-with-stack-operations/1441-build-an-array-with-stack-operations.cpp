class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        
        vector<int> base = {1};
        if(target == base){
            return {"Push"};
        }
        
        int m = target.size();
        int j=1;
        int i=1;
        int k=0;
        
        while(i<=n && j<m){
            while(!st.empty() && st.top() != target[k]){
                st.pop();
                ans.push_back("Pop");
            }
            
            st.push(i);
            i++;
            ans.push_back("Push");
            
            
            if(!st.empty() && target[j] == st.top()){
                j++;
                k++;
            }
        }
        
        vector<int> num;
        while(!st.empty()){
            num.push_back(st.top());
            st.pop();
        }
        reverse(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            cout<<num[i]<<" ";
        }
        
        return ans;
    }
};