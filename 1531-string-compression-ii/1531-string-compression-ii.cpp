int dp[101][27][101][101];
class Solution {
    public:
    unordered_set<int>possible_len={1,9,99};
    int solve(int ind,char lastchar,int lastcharcnt,int k,string &s,int n)
    {
        
        if(k<0) return INT_MAX/4; 
        if(ind==n) return 0; 

        int& ans=dp[ind][lastchar-'a'][lastcharcnt][k];
        if(ans!=-1) return ans;

        
         int not_delete;
         int del=solve(ind+1,lastchar,lastcharcnt,k-1,s,n);
       

         if(s[ind]==lastchar)
         { 
          not_delete=solve(ind+1,lastchar,lastcharcnt+1,k,s,n)+(possible_len.count(lastcharcnt)?1:0);
         }
         else
         {
             not_delete=solve(ind+1,s[ind],1,k,s,n)+1;
         }
         ans=min(del,not_delete);
         return ans;
    }

    int getLengthOfOptimalCompression(string s, int k) 
    {
        
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,'z'+1,0,k,s,n);
        
    }
    
};