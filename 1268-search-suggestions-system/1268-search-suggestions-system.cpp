class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(),products.end());
        
        vector<vector<string>> ans;
        int start = 0;
        int end = n-1;
        
        for(int i=0;i<searchWord.length();i++){
            while(start <= end && (i >= products[start].size() || products[start][i] < searchWord[i])){
                start++;
            }
            while(start <= end && (i >= products[end].size() || products[end][i] > searchWord[i])){
                end--;
            }
            
            ans.push_back({});
            
            for(int j=start; j<min(start+3,end+1); j++){
                ans.back().push_back(products[j]);
            }
        }
        
        return ans;
    }
};