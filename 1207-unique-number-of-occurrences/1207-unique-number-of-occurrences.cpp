class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        // for(auto it : arr){
        //     mp[it]++;
        // }
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        set<int> st;
        
        for(auto it: mp){
            if(st.find(it.second) != st.end()){
                return false;
            }
            else{
                st.insert(it.second);
            }
        }
        
        return true;
    }
};