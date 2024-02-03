class Solution {
public:
    vector<vector<int>>dp;
    
    int find(int index,int maxm,int len,vector<int>& arr, int k)
    {
        if(index==arr.size())
        {
            return len*maxm;       
        }
        
        int part=0,noPart=0;
        maxm=max(maxm,arr[index]);
        len++;
        
        if(dp[index][len]!=-1)
            return dp[index][len];
        
        if(len<k)
        {
            noPart=find(index+1,maxm,len,arr,k);    
        }
        part=len*maxm+find(index+1,INT_MIN,0,arr,k);
        
        return dp[index][len]=max(part,noPart);
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        
        return find(0,INT_MIN,0,arr,k);
    }
};