class Solution {
public:
    
    static bool compare(string &a,string &b){
        if(a.length() == b.length()){
            return a>b;
        }
        
        string temp1 = a+b;
        string temp2 = b+a;
        
        return temp1>temp2;
    }
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> st(n,"");
        bool flag = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                st[i] += to_string(nums[i]);
                flag = 1;
            }
            else{
                st[i] = "0";
            }
        }
        
        sort(st.begin(),st.end(),compare);
        string ans = "";
        
        for(auto i:st){
            ans += i;
        }
        
        return flag == 0 ? "0" : ans;
    }
};