class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)<abs(b) || (abs(a)==abs(b) && a>b);
        });
    }
};