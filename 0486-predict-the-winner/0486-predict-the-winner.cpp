class Solution {
    public:
    
    bool checkWin(int ans,int total){
	   return ans>=total-ans;
    }
    
    int maxScore(vector<int>&A,int total,int i,int j){
        if(i>j)
            return 0;
        
      return total-min(maxScore(A,total-A[i],i+1,j),maxScore(A,total-A[j],i,j-1));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int total=0; 
        for(auto x:nums)
            total+=x;
        
        return checkWin(maxScore(nums,total,0,nums.size()-1),total);
    }
};