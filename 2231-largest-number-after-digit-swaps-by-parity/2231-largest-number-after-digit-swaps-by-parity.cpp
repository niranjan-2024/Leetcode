class Solution {
public:
    int largestInteger(int num) {
        string nums = to_string(num);
        priority_queue<int> even,odd;
        
        for(auto s:nums){
            int temp = s-'0';
            
            if(temp%2 == 0){
                even.push(temp);
            }
            else{
                odd.push(temp);
            }
        }
        
        string ans = "";
        
        for(auto s:nums){
            int temp = s-'0';
            
            if(temp%2 == 0){
                ans += (even.top() + '0');
                even.pop();
            }
            else{
                ans += (odd.top() + '0');
                odd.pop();
            }
        }
        
        return stoi(ans);
    }
};