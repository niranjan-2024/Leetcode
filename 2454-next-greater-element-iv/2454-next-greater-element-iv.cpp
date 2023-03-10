class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        stack<int> stack1,stack2,temp;
        
        for(int i=0;i<n;i++){
            
            while(!stack2.empty() && nums[stack2.top()] < nums[i]){
                ans[stack2.top()] = nums[i];
                stack2.pop();
            }
            
            while(!stack1.empty() && nums[stack1.top()] < nums[i]){
                temp.push(stack1.top());
                stack1.pop();
            }
            
            while(!temp.empty()){
                stack2.push(temp.top());
                temp.pop();
            }
            
            stack1.push(i);
        }
        
        return ans;
    }
};