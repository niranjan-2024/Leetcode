class Solution {
public:
    int mod = 1e9+7;
    unordered_set<int> st;
    unordered_map<int,long long int> dp;
    
    long long int factorCount(int root){
        if(dp.count(root)){
            return dp[root];
        }
        
        long long int count = 1;
        
        for(auto val : st){
            if(root%val != 0){
                continue;
            }
            
            int factor1 = val;
            int factor2 = root/val;
            
            if(st.count(factor2)){
                count += factorCount(factor1)*factorCount(factor2);
                count %= mod;
            }
        }
        
        return dp[root] = count;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        st.insert(arr.begin(),arr.end());
        
        int ans = 0;
        
        for(auto root : arr){
            ans += factorCount(root);
            ans %= mod;
        }
        
        return ans;
    }
};