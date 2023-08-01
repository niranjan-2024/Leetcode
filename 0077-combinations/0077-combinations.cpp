class Solution {
public:

    void solve(vector<vector<int>> &result,vector<int> &temp,int start,int num,int n,int k){
        if(num == k){
            result.push_back(temp);
            return;
        }

        for(int i=start;i<n;i++){
            temp.push_back(i+1);
            solve(result,temp,i+1,num+1,n,k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp(0,k);

        if(n<k){
            return result;
        }

        solve(result,temp,0,0,n,k);
        return result;
    }
};